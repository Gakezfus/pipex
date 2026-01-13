/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elkan Choo <echoo@42mail.sutd.edu.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 12:59:35 by Elkan Choo        #+#    #+#             */
/*   Updated: 2025/12/05 19:25:38 by Elkan Choo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*calc_return(int n_eof, char *buf);
char	*get_next_line(int fd);
int		calc_leftover(char **buf, size_t *len,
			int *newline_index, char **leftover);
int		read_fd(char **buf, size_t *len, int *newline_index, int fd);
int		store_leftover(char **buf, size_t len,
			int newline_index, char **leftover);
int		ft_newline(char *str, int i);
void	ft_strlcpy(char *dst, const char *src, size_t size);

#endif
