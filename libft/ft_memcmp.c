/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoo <echoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 17:35:44 by echoo             #+#    #+#             */
/*   Updated: 2025/11/26 18:37:06 by echoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h>
#include <stdio.h>
#include <string.h>

// int ft_memcmp(const void *s1, const void *s2, size_t n);

// int	main(void)
// {
// 	int	v = 4;
// 	char x[] = {0, 0, 127, 0};
// 	char y[] = {0, 0, 42, 0};

// 	printf("%i\n", ft_memcmp(x, y, v));
// 	printf("%i\n", memcmp(x, y, v));
// }

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			count;
	unsigned char	*str1;
	unsigned char	*str2;

	count = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (count < n)
	{
		if (!(str1[count] == str2[count]))
			return (str1[count] - str2[count]);
		count++;
	}
	return (0);
}
