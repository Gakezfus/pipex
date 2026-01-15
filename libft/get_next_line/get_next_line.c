/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elkan Choo <echoo@42mail.sutd.edu.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 12:55:28 by Elkan Choo        #+#    #+#             */
/*   Updated: 2025/12/05 19:27:52 by Elkan Choo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <stdio.h>

#include "libft.h"

// int	main(void)
// {
// 	int	p[2];
// 	int	q[2];
// 	int	e[2];	

// 	pipe(q);
// 	pipe(p);
// 	pipe(e);
// 	write (p[1], "Let's read from the std input, see what happens\n", 48);
// 	write (p[1], "Testing the GNL function, let's hope it works\n", 46);
// 	write (p[1], "If we see this, that's great! If not, that sucks\n", 49);
// 	write (q[1], "\n\n\n\n\n\n", 10000);
// 	close(p[1]);
// 	close(q[1]);
// 	close(e[1]);
// 	char	*s1;
// 	char	*s2;
// 	char	*s3;
// 	s1 = get_next_line(p[0]);
// 	s2 = get_next_line(p[0]);
// 	s3 = get_next_line(p[0]);
// 	char *q1 = get_next_line(q[0]);
// 	char *q2 = get_next_line(q[0]);
// 	char *q3 = get_next_line(q[0]);
// 	char *q4 = get_next_line(q[0]);
// 	char *q5 = get_next_line(q[0]);
// 	char *q6 = get_next_line(q[0]);
// 	printf("q1: %s\n", q1);
// 	printf("q2: %s\n", q2);
// 	printf("q3: %s\n", q3);
// 	printf("q4: %s\n", q4);
// 	printf("q5: %s\n", q5);
// 	printf("q6: %s\n", q6);
// 	printf("invalid: %s\n", get_next_line(100));
// 	close(e[0]);
// 	printf("closed: %s\n", get_next_line(e[0]));
// 	printf("s1: %s", s1);
// 	printf("s2: %s", s2);
// 	printf("s3: %s", s3);
// 	free(s1);
// 	free(s2);
// 	free(s3);
// 	free(q1);
// 	free(q2);
// 	free(q3);
// 	free(q4);
// 	free(q5);
// 	free(q6);
// }

// Len represents the number of chars that have been processed
// (i.e. no newlines).
// newline_index represents the index at which the newline would be found
// after processed chars (i.e len)
// e.g. if char *buf has a newline, buf[len + newline] = '\0'
char	*get_next_line(int fd)
{
	char		*buf;
	size_t		len;
	int			newline_index;
	int			n_eof;
	static char	*leftover[1024];

	buf = NULL;
	len = 0;
	newline_index = -1;
	if (leftover[fd])
	{
		n_eof = calc_leftover(&buf, &len, &newline_index, &leftover[fd]);
		if (n_eof)
			return (calc_return(n_eof, buf));
	}
	n_eof = read_fd(&buf, &len, &newline_index, fd);
	if (n_eof < 0)
		return (free(buf), NULL);
	if (newline_index < BUFFER_SIZE - 1 && n_eof)
		if (store_leftover(&buf, len, newline_index, &leftover[fd]))
			return (free(buf), NULL);
	buf[newline_index + len + 1] = '\0';
	if (buf[0])
		return (buf);
	return (free(buf), NULL);
}

// Process any existing leftovers
int	calc_leftover(char **buf, size_t *len,
	int *newline_index, char **leftover)
{
	char	*new;

	new = NULL;
	*newline_index = ft_newline(*leftover, 1);
	if (*newline_index >= 0)
	{
		*buf = malloc(*newline_index + 2);
		ft_gnl_strlcpy(*buf, *leftover, *newline_index + 2);
		*len = ft_newline(*leftover + *newline_index + 1, 0);
		if ((*leftover)[*newline_index + 1])
		{
			new = malloc(*len + 1);
			if (new == NULL)
				return (-1);
			ft_gnl_strlcpy(new, *leftover + *newline_index + 1, *len + 1);
		}
		return (free(*leftover), *leftover = new, 1);
	}
	*len = ft_newline(*leftover, 0);
	*buf = malloc(*len + 1);
	if (*buf == NULL)
		return (-1);
	ft_gnl_strlcpy(*buf, *leftover, *len + 1);
	return (free(*leftover), *leftover = NULL, 0);
}

// Read from fd until a newline is found
int	read_fd(char **buf, size_t *len, int *newline_index, int fd)
{
	int		n_eof;
	char	*new;

	new = NULL;
	n_eof = 1;
	while (*newline_index < 0 && n_eof > 0)
	{
		new = malloc(*len + BUFFER_SIZE + 1);
		if (new == NULL)
			return (-1);
		if (*buf)
			ft_gnl_strlcpy(new, *buf, *len + 1);
		n_eof = read(fd, new + *len, BUFFER_SIZE);
		if (n_eof < 0)
			return (free(new), -1);
		new[*len + n_eof] = '\0';
		*newline_index = ft_newline(new + *len, 1);
		free(*buf);
		*buf = new;
		if (*newline_index < 0 && n_eof > 0)
			*len += BUFFER_SIZE;
	}
	return (n_eof);
}

// Create new leftovers if any, update buf
int	store_leftover(char **buf, size_t len,
	int newline_index, char **leftover)
{
	char	*new;

	if (!(*buf)[len + newline_index + 1])
		return (0);
	*leftover = malloc(BUFFER_SIZE - newline_index + 1);
	if (*leftover == NULL)
		return (1);
	ft_gnl_strlcpy(*leftover, *buf + len + newline_index + 1,
		BUFFER_SIZE - newline_index - 1 + 1);
	new = malloc(len + newline_index + 1 + 1);
	if (new == NULL)
		return (1);
	ft_gnl_strlcpy(new, *buf, len + newline_index + 1 + 1);
	free(*buf);
	*buf = new;
	return (0);
}
