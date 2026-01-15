/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elkan Choo <echoo@42mail.sutd.edu.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:19:03 by Elkan Choo        #+#    #+#             */
/*   Updated: 2025/12/05 19:25:01 by Elkan Choo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "libft.h"

char	*calc_return(int n_eof, char *buf)
{
	if (n_eof > 0)
		return (buf);
	free(buf);
	return (NULL);
}

// If nl, the function finds the index of the newline, and returns -1 if no 
// newline is found. If nl = 0, the function acts like ft_strlen.
int	ft_newline(char *str, int nl)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (str[index] == '\n' && nl)
		{
			return (index);
		}
		index++;
	}
	if (nl)
		return (-1);
	return (index);
}

void	ft_gnl_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	count;

	count = 0;
	while (count + 1 < size && src[count])
	{
		dst[count] = src[count];
		count++;
	}
	if (size > 0)
		dst[count] = '\0';
}
