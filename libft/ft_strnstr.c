/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoo <echoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 17:46:33 by echoo             #+#    #+#             */
/*   Updated: 2025/11/26 18:26:33 by echoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h>
// #include <bsd/string.h>
// #include <stdio.h>

// char	*ft_strnstr(const char *big, const char *little, size_t len);

// int	main(void)
// {
// 	int	length = 8;
// 	char *to_find = "cd";
// 	char *string = "aaabcabcd";
// 	char *x = ft_strnstr(string, to_find, length);
// 	char *y = strnstr(string, to_find, length);

// 	printf("%s\n", x);
// 	printf("%s\n", y);
// }

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	big_index;
	size_t	l_index;

	if (!little[0])
		return ((char *)big);
	big_index = 0;
	while (big[big_index] && big_index < len)
	{
		l_index = 0;
		while (big[big_index + l_index] == little[l_index]
			&& big_index + l_index < len)
		{
			l_index++;
			if (!little[l_index])
			{
				return ((char *)big + big_index);
			}
		}
		big_index++;
	}
	return (NULL);
}
