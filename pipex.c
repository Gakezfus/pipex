/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkan <elkan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 16:04:46 by elkan             #+#    #+#             */
/*   Updated: 2026/01/19 02:43:41 by elkan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>

void	setup(int argc, char *argv[], char *envp[], t_pars *pars);
void	setup_cmds(int argc, char *argv[], t_pars *pars);
char	**cmd_array(char *cmd, int (is_sep)(char), char *path, char *cmd_word);
pid_t	child_last(char *cmd, char *envp[], int pip[2], int file2_fd);

int	main(int argc, char *argv[], char *envp[])
{
	t_pars	pars;
	int		index;

	index = 0;
	setup(argc, argv, envp, &pars);
	pars.cmd_pid = malloc(pars.cmd_count * sizeof(pid_t));
	pars.pipes = malloc((pars.cmd_count - 1) * sizeof(int[2]));
	if (pars.cmd_pid == NULL)
		return (free_all(NULL, NULL, NULL, &pars), 1);
	while (index < pars.cmd_count)
	{
		if (pipe(pars.pipes[index]))
			return (free_all(NULL, NULL, NULL, &pars), 1);
		index++;
	}
	pars.cmd_pid[0] = first_cmd(argv[2], pars.file1_fd,
		pars.pipes[0][1], &pars);
	other_commands(argv, &pars);
	if (WIFEXITED(pars.last_cmd_status))
	{
		if (WEXITSTATUS(pars.last_cmd_status))
			pars.error = WEXITSTATUS(pars.last_cmd_status);
	}
	free_all(NULL, NULL, NULL, &pars);
	return (pars.error);
}

void	setup(int argc, char *argv[], char *envp[], t_pars *pars)
{
	pars->envp = envp;
	pars->error = 0;
	if (ft_strncmp(argv[1], "here_doc", 9))
		pars->here_doc = 0;
	else
		pars->here_doc = 1;
	pars->cmd_count = argc - 3 - pars->here_doc;
	if (!pars->here_doc && argc < 5)
	{
		write(2, "Usage: ./pipex file1 first_cmd ... last_cmd file2\n", 50);
		exit (1);
	}
	else if (pars->here_doc && argc < 6)
	{
		write(2, "Usage: ./pipex here_doc LIMITER first_cmd ...\
			last_cmd file2\n", 50);
		exit (1);
	}
	pars->file2_fd = open_file2(argv, pars);
	if (pars->here_doc)
		pars->file1_fd = get_heredoc(argv[2]);
	else
		pars->file1_fd = open_file1(argv, pars);
}

char	**cmd_array(char *cmd, int (is_sep)(char), char *path, char *cmd_word)
{
	char	**cmds;

	cmds = ft_split_f(cmd, is_sep);
	if (cmds == NULL)
	{
		free_all(path, cmds, cmd_word, NULL);
		exit (1);
	}
	return (cmds);
}
