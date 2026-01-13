/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoo <echoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 15:05:55 by echoo             #+#    #+#             */
/*   Updated: 2025/11/26 17:59:50 by echoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h>
#include <string.h>
#include <stdio.h>

// char *ft_strchr(const char *s, int c);

// int	main(void)
// {
// 	int	x = 0;
// 	char *y = ft_strchr("tripouille", x);
// 	char *z = strchr("tripouille", x);

// 	printf("%s\n", y);
// 	printf("%s\n", z);
// }

char	*ft_strchr(const char *s, int c)
{
	int				str_index;
	unsigned char	ch;

	ch = (unsigned char)c;
	str_index = 0;
	while (s[str_index])
	{
		if (s[str_index] == ch)
		{
			return ((char *)(s) + str_index);
		}
		str_index++;
	}
	if (s[str_index] == ch)
	{
		return ((char *)(s) + str_index);
	}
	return (NULL);
}
