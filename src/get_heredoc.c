/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_heredoc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkan <elkan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 16:36:48 by elkan             #+#    #+#             */
/*   Updated: 2026/01/18 18:34:35 by elkan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex.h"

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	get_heredoc(char *limiter)
{
	char	*line;
	int		index;
	int		here_d[2];
	int		lim_len;

	lim_len = ft_strlen(limiter);
	if (pipe(here_d))
	{
		perror("pipe");
		return (1);
	}
	line = get_next_line(0);
	while (line && (ft_strncmp(line, limiter, lim_len)
			|| ft_strncmp(line + lim_len, "\n", 1)))
	{
		index = 0;
		while (line[index])
			write(here_d[1], &line[index++], 1);
		free(line);
		line = get_next_line(0);
	}
	free(line);
	close(here_d[1]);
	return (here_d[0]);
}
