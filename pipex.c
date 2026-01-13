/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkan <elkan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 17:38:33 by elkan             #+#    #+#             */
/*   Updated: 2026/01/13 22:37:35 by elkan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int	main(int argc, char *argv[])
{
	int	file1_fd;
	int	file2_fd;
	int	error;
	int	fail;

	error = 0;
	fail = 0;
	if (argc != 5)
		return(write(2, "Usage: ./pipex file1 cmd1 cmd2 file2\n", 37), 1);
	file2_fd = open(argv[4], O_WRONLY, O_CREAT, O_TRUNC);
	if (file2_fd < 0)
	{
		ft_printf("pipex: ");
		error = 1;
		fail = 1;
		perror(argv[4]);
	}
	file1_fd = open(argv[1], O_RDONLY);
	if (file1_fd < 0)
	{
		fail = 1;
		ft_printf("pipex: ");
		perror(argv[1]);
	}
	if (fail)
		return (error);
	perror(argv[2]);
}
