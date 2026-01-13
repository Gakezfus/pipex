/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elkan Choo <echoo@42mail.sutd.edu.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 04:04:47 by Elkan Choo        #+#    #+#             */
/*   Updated: 2025/12/26 14:51:19 by Elkan Choo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h>

int	*ft_intchr(const int *s, int c, size_t n)
{
	size_t	str_index;

	str_index = 0;
	while (str_index < n)
	{
		if (s[str_index] == c)
		{
			return ((int *)s + str_index);
		}
		str_index++;
	}
	return (NULL);
}
