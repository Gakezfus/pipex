/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elkan Choo <echoo@42mail.sutd.edu.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 16:24:36 by echoo             #+#    #+#             */
/*   Updated: 2025/12/26 14:46:13 by Elkan Choo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h>
#include <string.h>
// #include <stdio.h>

// char	*ft_strrchr(const char *s, int c);

// int	main(void)
// {
// 	int	x = 't' + 256;
// 	char *y = ft_strrchr("tripouille", x);
// 	char *z = strrchr("tripouille", x);

// 	printf("%s\n", y);
// 	printf("%s\n", z);
// }

char	*ft_strrchr(const char *s, int c)
{
	int				str_index;
	int				s_strlen;
	unsigned char	ch;

	ch = (unsigned char)c;
	s_strlen = ft_strlen(s);
	str_index = 0;
	while (str_index <= s_strlen)
	{
		if (s[s_strlen - str_index] == ch)
		{
			return ((char *)(s) + s_strlen - str_index);
		}
		str_index++;
	}
	return (NULL);
}
