/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkan <elkan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 17:38:33 by elkan             #+#    #+#             */
/*   Updated: 2026/01/17 17:14:06 by elkan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>

void	setup(int argc, char *argv[], t_pars *pars);
char	**setup_cmds(char *cmd, int (is_sep)(char), char *path, char *cmd_word);
pid_t	child_1(char *cmd, char *envp[], int pip[2], int file1_fd);
pid_t	child_2(char *cmd, char *envp[], int pip[2], int file2_fd);

int	main(int argc, char *argv[], char *envp[])
{
	t_pars	pars;

	setup(argc, argv, &pars);
	pipe(pars.pip);
	pars.child1_pid = child_1(argv[2], envp, pars.pip, pars.file1_fd);
	pars.child2_pid = child_2(argv[3], envp, pars.pip, pars.file2_fd);
	close(pars.pip[0]);
	close(pars.pip[1]);
	waitpid(pars.child1_pid, &pars.child_1_status, 0);
	waitpid(pars.child2_pid, &pars.child_2_status, 0);
	if (WIFEXITED(pars.child_2_status))
	{
		if (WEXITSTATUS(pars.child_2_status))
			pars.error = WEXITSTATUS(pars.child_2_status);
	}
	return (pars.error);
}

void	setup(int argc, char *argv[], t_pars *pars)
{
	pars->error = 0;
	if (argc != 5)
	{
		write(2, "Usage: ./pipex file1 cmd1 cmd2 file2\n", 37);
		exit (1);
	}
	pars->file2_fd = open_file2(argv, pars);
	pars->file1_fd = open_file1(argv);
}

pid_t	child_1(char *cmd, char *envp[], int pip[2], int file1_fd)
{
	pid_t	child;
	char	*path;
	char	**cmds;
	char	*cmd_word;

	child = fork();
	if (child == 0)
	{
		cmd_word = first_word(cmd, is_sep);
		path = get_path(cmd_word, envp);
		dup2(file1_fd, 0);
		dup2(pip[1], 1);
		close(file1_fd);
		close(pip[1]);
		close(pip[0]);
		cmds = setup_cmds(cmd, is_sep, path, cmd_word);
		execve(path, cmds, envp);
		perror("execve");
		free(path);
		exit (1);
	}
	return (child);
}

pid_t	child_2(char *cmd, char *envp[], int pip[2], int file2_fd)
{
	pid_t	child;
	char	*path;
	char	**cmds;
	char	*cmd_word;

	child = fork();
	if (child == 0)
	{
		cmd_word = first_word(cmd, is_sep);
		path = get_path(cmd_word, envp);
		dup2(pip[0], 0);
		dup2(file2_fd, 1);
		close(file2_fd);
		close(pip[0]);
		close(pip[1]);
		cmds = setup_cmds(cmd, is_sep, path, cmd_word);
		execve(path, cmds, envp);
		perror("execve");
		free(path);
		exit (1);
	}
	return (child);
}

char	**setup_cmds(char *cmd, int (is_sep)(char), char *path, char *cmd_word)
{
	char	**cmds;

	cmds = ft_split_f(cmd, is_sep);
	if (cmds == NULL)
	{
		free_all(path, cmds, cmd_word);
		exit (1);
	}
	return (cmds);
}
