/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkan <elkan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 17:38:33 by elkan             #+#    #+#             */
/*   Updated: 2026/01/14 22:53:23 by elkan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>

int		open_file1(char *argv[], int *error, int *fail);
int		open_file2(char *argv[], int *error, int *fail);
void	setup(int argc, char *argv[], int *file1_fd, int *file2_fd);
void	child_1(char *cmd, char *envp[], int pip[2], int file1_fd);
void	child_2(char *cmd, char *envp[], int pip[2], int file2_fd);

int	main(int argc, char *argv[], char *envp[])
{
	int	file1_fd;
	int	file2_fd;
	int	pip[2];

	setup(argc, argv, &file1_fd, &file2_fd);
	pipe(pip);
	child_1(argv[2], envp, pip, file1_fd);
	child_2(argv[3], envp, pip, file2_fd);
	close(pip[0]);
	close(pip[1]);
	waitpid(file1_fd, NULL, 0);
	waitpid(file2_fd, NULL, 0);
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
	*file1_fd = open_file1(argv, &error, &fail);
	if (fail)
		exit (error);
}

int	open_file1(char *argv[], int *error, int *fail)
{
	int	to_return;

	to_return = open(argv[1], O_RDONLY);
	if (to_return < 0)
	{
		*fail = 1;
		write(2, "pipex: ", 7);
		perror(argv[1]);
	}
	(void)error;
	return (to_return);
}

int	open_file2(char *argv[], int *error, int *fail)
{
	int	to_return;

	to_return = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (to_return < 0)
	{
		*error = 1;
		*fail = 1;
		write(2, "pipex: ", 7);
		perror(argv[4]);
	}
	return (to_return);
}

void	child_1(char *cmd, char *envp[], int pip[2], int file1_fd)
{
	pid_t	child;
	char	*path;
	char	**cmds;

	path = get_path(cmd, envp);
	child = fork();
	if (child == 0)
	{
		dup2(file1_fd, 0);
		dup2(pip[1], 1);
		close(file1_fd);
		close(pip[1]);
		close(pip[0]);
		cmds = ft_split(cmd, ' ');
		if (cmds == NULL)
		{
			free(path);
			perror("ft_split");
			exit (1);
		}
		dprintf(2, "path: %s\n", path);
		for (int i = 0; cmds[i]; i++)
		{
			dprintf(2, "cmds[%i]: %s\n", i, cmds[i]);
		}
		execve(path, cmds, envp);
		perror("execve");
		exit (1);
	}
}

void	child_2(char *cmd, char *envp[], int pip[2], int file2_fd)
{
	pid_t	child;
	char	*path;
	char	**cmds;

	path = get_path(cmd, envp);
	child = fork();
	if (child == 0)
	{
		dup2(pip[0], 0);
		dup2(file2_fd, 1);
		close(file2_fd);
		close(pip[0]);
		close(pip[1]);
		cmds = ft_split(cmd, ' ');
		if (cmds == NULL)
		{
			free(path);
			perror("ft_split");
			exit (1);
		}
		execve(path, cmds, envp);
		perror("execve");
		exit (1);
	}
}
