/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoo <echoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:13:25 by echoo             #+#    #+#             */
/*   Updated: 2025/11/24 15:50:23 by echoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h>
// #include <stdio.h>
// #include <string.h>

// void	*ft_memmove(void *dest, const void *src, size_t n);

// int	main(void)
// {
// 	size_t	x = 3;
// 	char src[30] = "Hello world";
// 	char *dest = src + 15;

// 	ft_memmove(dest, src, x);
// 	printf("%s\n", dest);
// }

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				count;
	unsigned char		*des;
	const unsigned char	*source;

	if (((dest - src > (unsigned int)n) || src > dest))
	{
		ft_memcpy(dest, src, n);
	}
	else
	{
		des = dest;
		source = src;
		count = 1;
		while (count <= n)
		{
			des[n - count] = source[n - count];
			count++;
		}
	}
	return (dest);
}
