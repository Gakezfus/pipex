/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkan <elkan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 18:58:04 by elkan             #+#    #+#             */
/*   Updated: 2026/01/19 17:09:14 by elkan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

pid_t	first_cmd(char *cmd, int read, int write, t_pars *pars);
pid_t	command(char *cmd, int read[2], int write, t_pars *pars);
void	commands(char *argv[], t_pars *pars);
void	close_all(t_pars *pars);

void	commands(char *argv[], t_pars *pars)
{
	int	index;

	pars->cmd_pid[0] = first_cmd(argv[2 + pars->here_doc], pars->file1_fd,
			pars->pipes[0][1], pars);
	close(pars->file1_fd);
	pars->file1_fd = -1;
	index = 0;
	while (index < pars->cmd_count - 2)
	{
		pars->cmd_pid[index + 1] = command(argv[3 + pars->here_doc + index],
				pars->pipes[index], pars->pipes[index + 1][1], pars);
		close(pars->pipes[index][0]);
		pars->pipes[index][0] = -1;
		close(pars->pipes[index][1]);
		pars->pipes[index][1] = -1;
		index++;
	}
	pars->cmd_pid[index + 1] = command(argv[3 + pars->here_doc + index],
			pars->pipes[index], pars->file2_fd, pars);
	close_all(pars);
	index = 0;
	while (index < pars->cmd_count)
		waitpid(pars->cmd_pid[index++], &pars->last_cmd_status, 0);
}

pid_t	first_cmd(char *cmd, int read, int write, t_pars *pars)
{
	pid_t	child;
	char	*path;
	char	**cmds;
	char	*cmd_word;

	child = fork();
	if (child == 0)
	{
		cmd_word = first_word(cmd, is_sep);
		path = get_path(cmd_word, pars->envp, pars);
		dup2(read, 0);
		dup2(write, 1);
		close_all(pars);
		cmds = cmd_array(cmd, path, cmd_word, pars);
		if (read >= 0)
		{
			execve(path, cmds, pars->envp);
			perror("execve");
		}
		free_all(path, cmds, cmd_word, pars);
		exit (1);
	}
	return (child);
}

pid_t	command(char *cmd, int read[2], int write, t_pars *pars)
{
	pid_t	child;
	char	*path;
	char	**cmds;
	char	*cmd_word;

	child = fork();
	if (child == 0)
	{
		cmd_word = first_word(cmd, is_sep);
		path = get_path(cmd_word, pars->envp, pars);
		dup2(read[0], 0);
		dup2(write, 1);
		close_all(pars);
		cmds = cmd_array(cmd, path, cmd_word, pars);
		if (read[0] >= 0)
		{
			execve(path, cmds, pars->envp);
			perror("execve");
		}
		free_all(path, cmds, cmd_word, NULL);
		exit (1);
	}
	return (child);
}

void	close_all(t_pars *pars)
{
	int	index;

	index = 0;
	while (index < pars->cmd_count - 1)
	{
		if (pars->pipes[index][0] >= 0)
			close(pars->pipes[index][0]);
		if (pars->pipes[index][1] >= 0)
			close(pars->pipes[index][1]);
		index++;
	}
	if (pars->file1_fd >= 0)
		close(pars->file1_fd);
	if (pars->file2_fd >= 0)
		close(pars->file2_fd);
}
