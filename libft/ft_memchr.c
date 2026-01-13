/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoo <echoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 16:56:11 by echoo             #+#    #+#             */
/*   Updated: 2025/11/24 15:50:20 by echoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h>
// #include <stdio.h>
// #include <string.h>
// void	*ft_memchr(const void *s, int c, size_t n);

// int	main(void)
// {
// 	char *x = "The big brown fox jumped over the lazy dog";
// 	char y = 'o';
// 	size_t z = 20;

// 	printf("%s\n", (char*)memchr(x, y, z));
// 	printf("%s\n", (char*)ft_memchr(x, y, z));
// }

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;
	size_t				str_index;

	str = s;
	str_index = 0;
	while (str_index < n)
	{
		if (str[str_index] == (unsigned char)c)
		{
			return ((void *)(str + str_index));
		}
		str_index++;
	}
	return (NULL);
}
