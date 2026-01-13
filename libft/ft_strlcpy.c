/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoo <echoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:11:25 by echoo             #+#    #+#             */
/*   Updated: 2025/11/26 18:18:46 by echoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h>
// #include <stdio.h>
// #include <bsd/string.h>

// size_t	ft_strlcpy(char *dst, const char *src, size_t size);

// int	main(void)
// {
// 	int	x = 0;

// 	char *src = "Hello world";
// 	char dest[10];
// 	memset(dest, 'A', 10);

// 	printf("%li\n", ft_strlcpy(dest, src, x));
// 	printf("%s\n", dest);
// }

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
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
	return (ft_strlen(src));
}
