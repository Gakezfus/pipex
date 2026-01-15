/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkan <elkan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 17:38:33 by elkan             #+#    #+#             */
/*   Updated: 2026/01/16 01:03:57 by elkan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>

void	setup(int argc, char *argv[], int *file1_fd, int *file2_fd);
pid_t	child_1(char *cmd, char *envp[], int pip[2], int file1_fd);
pid_t	child_2(char *cmd, char *envp[], int pip[2], int file2_fd);

int	main(int argc, char *argv[], char *envp[])
{
	int		file1_fd;
	int		file2_fd;
	int		pip[2];
	pid_t	child1_pid;
	pid_t	child2_pid;

	setup(argc, argv, &file1_fd, &file2_fd);
	pipe(pip);
	child1_pid = child_1(argv[2], envp, pip, file1_fd);
	child2_pid = child_2(argv[3], envp, pip, file2_fd);
	close(pip[0]);
	close(pip[1]);
	waitpid(child1_pid, &file1_fd, 0);
	waitpid(child2_pid, &file2_fd, 0);
}

void	setup(int argc, char *argv[], int *file1_fd, int *file2_fd)
{
	int	error;
	int	fail;

	error = 0;
	fail = 0;
	if (argc != 5)
	{
		write(2, "Usage: ./pipex file1 cmd1 cmd2 file2\n", 37);
		exit (1);
	}
	*file2_fd = open_file2(argv, &error, &fail);
	*file1_fd = open_file1(argv, &fail);
	if (fail)
		exit (error);
}

pid_t	child_1(char *cmd, char *envp[], int pip[2], int file1_fd)
{
	pid_t	child;
	char	*path;
	char	**cmds;

	child = fork();
	if (child == 0)
	{
		path = get_path(first_word(cmd, is_sep), envp);
		dup2(file1_fd, 0);
		dup2(pip[1], 1);
		close(file1_fd);
		close(pip[1]);
		close(pip[0]);
		cmds = ft_split_f(cmd, is_sep);
		if (cmds == NULL)
		{
			free(path);
			perror("ft_split_f");
			exit (1);
		}
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

	child = fork();
	if (child == 0)
	{
		path = get_path(first_word(cmd, is_sep), envp);
		dup2(pip[0], 0);
		dup2(file2_fd, 1);
		close(file2_fd);
		close(pip[0]);
		close(pip[1]);
		cmds = ft_split_f(cmd, is_sep);
		if (cmds == NULL)
		{
			free(path);
			perror("ft_split_f");
			exit (1);
		}
		execve(path, cmds, envp);
		perror("execve");
		free(path);
		exit (1);
	}
	return (child);
}
