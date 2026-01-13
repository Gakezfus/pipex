/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoo <echoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:48:57 by echoo             #+#    #+#             */
/*   Updated: 2025/11/26 19:18:56 by echoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>
// #include <stdio.h>

// char	*ft_substr(char const *s, unsigned int start, size_t len);

// int	main(void)
// {
// 	char	*str = "tripouille";
// 	char	*sub;

// 	sub = ft_substr(str, 100, 1);
// 	printf("%s\n", sub);
// }

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	index;

	index = 0;
	if (start > ft_strlen(s))
	{
		sub = malloc(1);
		sub[index] = '\0';
		return (sub);
	}
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	sub = malloc(len + 1);
	if (sub == NULL)
		return (NULL);
	while (index < len && s[start + index])
	{
		sub[index] = s[start + index];
		index++;
	}
	sub[index] = '\0';
	return (sub);
}
