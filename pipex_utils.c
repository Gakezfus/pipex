/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkan <elkan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:57:56 by elkan             #+#    #+#             */
/*   Updated: 2026/01/19 01:21:19 by elkan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex.h"

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

char	*first_word(char *str, int (is_sep)(char));
int		is_sep(char c);
int		open_file1(char *argv[], t_pars *pars);
int		open_file2(char *argv[], t_pars *pars);
void	free_all(char *path, char **cmds, char *cmd_word, t_pars *pars);

char	*first_word(char *str, int (is_sep)(char))
{
	int		index;
	char	*to_return;

	index = 0;
	while (is_sep(str[index]))
		index++;
	while (!is_sep(str[index]))
		index++;
	to_return = malloc(index + 1);
	ft_strlcpy(to_return, str, index + 1);
	return (to_return);
}

int	is_sep(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

int	open_file1(char *argv[], t_pars *pars)
{
	int	to_return;

	to_return = open(argv[1 + pars->here_doc], O_RDONLY);
	if (to_return < 0)
	{
		write(2, "pipex: ", 7);
		perror(argv[1]);
	}
	return (to_return);
}

int	open_file2(char *argv[], t_pars *pars)
{
	int	to_return;

	if (pars->here_doc)
		to_return = open(argv[5], O_WRONLY | O_CREAT | O_APPEND, 0666);
	else
		to_return = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (to_return < 0)
	{
		pars->error = 1;
		write(2, "pipex: ", 7);
		perror(argv[4]);
	}
	return (to_return);
}

void	free_all(char *path, char **cmds, char *cmd_word, t_pars *pars)
{
	free(path);
	free(cmd_word);
	ft_free_arrays((void **)cmds);
	if (pars && pars->cmd_count)
	{
		free(pars->pipes);
		free(pars->cmd_pid);
	}
}
