/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoo <echoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 15:47:26 by echoo             #+#    #+#             */
/*   Updated: 2025/11/24 15:50:28 by echoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h>
// #include <stdio.h>
// #include <bsd/string.h>

// size_t	ft_strlcat(char *dest, const char *src, size_t size);

// int	main(void)
// {
// 	char dest[25] = "I am ";
// 	char src[25] = "42Born to code";
// 	printf("%li\n", ft_strlcat(dest, src, 22));
// 	printf("%s\n", dest);
// }

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	count;

	dest_len = 0;
	while (dest_len < size && dest[dest_len])
	{
		dest_len++;
	}
	count = 0;
	while ((count + dest_len + 1 < size) && src[count])
	{
		dest[count + dest_len] = src[count];
		count++;
	}
	if (size <= dest_len)
	{
		while (src[count])
			count++;
		return (size + count);
	}
	dest[count + dest_len] = '\0';
	return (ft_strlen(src) + dest_len);
}
