/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoo <echoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:11:56 by echoo             #+#    #+#             */
/*   Updated: 2025/11/24 15:50:24 by echoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h>
// #include <stdio.h>
// #include <string.h>

// void	*ft_memset(void *s, int c, size_t n);

// int	main(void)
// {
// 	int x = 1;
// 	char s[x + 1];
// 	char t[x + 1];

// 	s[x] = '\0';
// 	t[x] = '\0';
// 	memset(s, 'x', x);
// 	printf("%s\n", s);
// 	ft_memset(t, 'x', x);
// 	printf("%s\n", t);
// }

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			count;
	unsigned char	*p;

	p = s;
	count = 0;
	while (count < n)
	{
		p[count] = (unsigned char)c;
		count++;
	}
	return (s);
}
