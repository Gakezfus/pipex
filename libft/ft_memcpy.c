/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoo <echoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:12:50 by echoo             #+#    #+#             */
/*   Updated: 2025/11/24 15:50:22 by echoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h>
// #include <stdio.h>
// #include <string.h>

// void	*ft_memcpy(void *dest, const void *src, size_t n);

// int	main(void)
// {
// 	size_t	x = 10;
// 	char *src = "Hello world";
// 	char dest1[x];
// 	char dest2[x];

// 	memcpy(dest1, src, x);
// 	ft_memcpy(dest2, src, x);
// 	printf("%s\n", dest1);
// 	printf("%s\n", dest2);
// }

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				count;
	unsigned char		*des;
	const unsigned char	*source;

	des = dest;
	source = src;
	count = 0;
	while (count < n)
	{
		des[count] = source[count];
		count++;
	}
	return (dest);
}
