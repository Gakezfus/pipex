/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elkan Choo <echoo@42mail.sutd.edu.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 13:53:28 by Elkan Choo        #+#    #+#             */
/*   Updated: 2026/01/20 15:36:16 by Elkan Choo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex.h"

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char	*get_path(char *cmd, char *envp[], t_pars *pars);
char	*get_path2(char *cmd, char **envp, t_pars *pars);
void	make_full_path(char **to_return, char *path, char *cmd);
void	check_empty(char *cmd, t_pars *pars);

char	*get_path(char *cmd, char *envp[], t_pars *pars)
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
	check_empty(cmd, pars);
	return (get_path2(cmd, envp, pars));
}

char	*get_path2(char *cmd, char **envp, t_pars *pars)
{
	int		index;
	char	*to_return;
	char	**path;

	while (ft_strncmp(*envp, "PATH=/", 6))
		envp++;
	path = ft_split(*envp + 5, ':');
	index = 0;
	while (path[index])
	{
		make_full_path(&to_return, path[index++], cmd);
		if (!access(to_return, F_OK))
		{
			if (access(to_return, X_OK) == 0)
				return (ft_free_arrays((void **)path), to_return);
			perror(cmd);
			exit(126);
		}
		free(to_return);
	}
	dprintf(2, "%s: command not found\n", cmd);
	free_all(cmd, path, NULL, pars);
	exit(127);
}

void	make_full_path(char **to_return, char *path, char *cmd)
{
	*to_return = ft_strdup(path);
	if (ft_merge_strings_var(to_return, 2, "/", cmd))
	{
		write(2, "pipex: ", 7);
		perror("ft_merge_strings");
		exit(1);
	}
}

void	check_empty(char *cmd, t_pars *pars)
{
	if (!*cmd)
	{
		dprintf(2, "'': command not found\n");
		free_all(cmd, NULL, NULL, pars);
		exit(127);
	}
}
