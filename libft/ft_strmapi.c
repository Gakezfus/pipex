/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoo <echoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:01:58 by echoo             #+#    #+#             */
/*   Updated: 2025/11/26 19:50:11 by echoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>
// #include <stdio.h>

// char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
// char ft_cipher(unsigned int index, char c);

// int	main(void)
// {
// 	printf("%s\n", ft_strmapi("Hello 42 world", ft_cipher));
// }

// char ft_cipher(unsigned int index, char c)
// {
// 	if (index > 1)
// 	{
// 		c++;
// 	}
// 	return (c);
// }

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*to_return;
	unsigned int	index;

	to_return = malloc(ft_strlen(s) + 1);
	if (to_return == NULL)
		return (NULL);
	index = 0;
	while (s[index])
	{
		to_return[index] = f(index, s[index]);
		index++;
	}
	to_return[index] = '\0';
	return (to_return);
}
