/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkan <elkan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 13:53:28 by Elkan Choo        #+#    #+#             */
/*   Updated: 2026/01/15 22:08:35 by elkan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex.h"

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char	*get_path(char *cmd, char *envp[]);
char	*get_path2(char *cmd, char *envp[]);

char	*get_path(char *cmd, char *envp[])
{
	char	*to_return;

	if (ft_strchr(cmd, '/'))
	{
		to_return = ft_strdup(cmd);
		if (to_return == NULL)
		{
			write(2, "pipex: ", 7);
			perror(cmd);
			exit(1);
		}
		if (access(cmd, X_OK) == 0)
			return (to_return);
		free(to_return);
		write(2, "pipex: ", 7);
		perror(cmd);
		exit(1);
	}
	return (get_path2(cmd, envp));
}

char	*get_path2(char *cmd, char *envp[])
{
	int		index;
	char	*to_return;
	char	**path;

	index = 0;
	while (ft_strncmp(envp[index], "PATH=/", 6))
		index++;
	path = ft_split(envp[index] + 5, ':');
	index = 0;
	while (path[index])
	{
		to_return = ft_strdup(path[index]);
		if (ft_merge_strings_var(&to_return, 2, "/", cmd))
		{
			write(2, "pipex: ", 7);
			perror("ft_merge_strings");
			exit(1);
		}
		if (!access(to_return, F_OK))
		{
			if (access(to_return, X_OK) == 0)
				return (to_return);
			dprintf(2, "%s: Permission denied\n", cmd);
			exit(126);
		}
		free(to_return);
		index++;
	}
	dprintf(2, "%s: command not found\n", cmd);
	exit(127);
	return (NULL);
}
