/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoo <echoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:12:03 by echoo             #+#    #+#             */
/*   Updated: 2025/11/24 15:50:12 by echoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h>
// #include <stdio.h>
// #include <string.h>

// void	ft_bzero(void *s, size_t n);

// int	main(void)
// {
// 	int x = 10;
// 	int	s_count;
// 	int	t_count;
// 	char s[x];
// 	char t[x];

// 	bzero(s, x);
// 	ft_bzero(t, x);
// 	for (int i = 0; i < x; i++)
// 	{
// 		if (!s[i])
// 		{
// 			s_count++;
// 		}
// 		if (!t[i])
// 		{
// 			t_count++;
// 		}
// 	}
// 	printf("s has %i nulls \n", s_count);
// 	printf("t has %i nulls \n", t_count);
// }

void	ft_bzero(void *s, size_t n)
{
	size_t			count;
	unsigned char	*p;

	p = s;
	count = 0;
	while (count < n)
	{
		p[count] = '\0';
		count++;
	}
}
