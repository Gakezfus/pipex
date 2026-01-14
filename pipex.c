/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkan <elkan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 17:38:33 by elkan             #+#    #+#             */
/*   Updated: 2026/01/14 11:17:29 by elkan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int		open_file1(char *argv[], int *error, int *fail);
int		open_file2(char *argv[], int *error, int *fail);
void	setup(int argc, char *argv[], int *file1_fd, int *file2_fd);
void	child_1(char *argv[], char *envp[], int pip[2], int file1_fd);

int	main(int argc, char *argv[], char *envp[])
{
	int	file1_fd;
	int	file2_fd;
	int	pip[2];

	setup(argc, argv, &file1_fd, &file2_fd);
	pipe(pip);
	child_1 = fork();
	perror(argv[2]);
}

void	setup(int argc, char *argv[], int *file1_fd, int *file2_fd)
{
	int	file1_fd;
	int	file2_fd;
	int	error;
	int	fail;

	error = 0;
	fail = 0;
	if (argc != 5)
		return(write(2, "Usage: ./pipex file1 cmd1 cmd2 file2\n", 37), 1);
	file2_fd = open_file2(argv, &error, &fail);
	file1_fd = open_file1(argv, &error, &fail);
	if (fail)
		return (error);
}

int	open_file1(char *argv[], int *error, int *fail)
{
	int	to_return;

	to_return = open(argv[1], O_RDONLY);
	if (file1_fd < 0)
	{
		*fail = 1;
		write(2, "pipex: ", 7);
		perror(argv[1]);
	}
}

int	open_file2(char *argv[], int *error, int *fail)
{
	int	to_return;

	to_return = open(argv[4], O_WRONLY, O_CREAT, O_TRUNC);
	if (file2_fd < 0)
	{
		*error = 1;
		*fail = 1;
		write(2, "pipex: ", 7);
		perror(argv[4]);
	}
}

void	child_1(char *argv[], char *envp[], int pip_0, int file1_fd)
{
	pid_t child;
	char *path;

	// TODO
	path = get_path();
	child = fork();
	if (child == 0)
	{
		dup2(file1_fd, 0);
		dup2(pip_0, 1);
		close(file1_fd);
		close(pip_0);
		execve()
	}
}
