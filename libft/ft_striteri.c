/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoo <echoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:47:18 by echoo             #+#    #+#             */
/*   Updated: 2025/11/26 13:51:17 by echoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

// void	ft_striteri(char *s, void (*f)(unsigned int, char*));
// void	ft_cipher(unsigned int index, char *c);

// int	main(void)
// {
// 	char	str[15] = "Hello 42 world";
// 	ft_striteri(str, ft_cipher);
// 	printf("%s\n", str);
// }

// void	ft_cipher(unsigned int index, char *c)
// {
// 	if (index > 1)
// 	{
// 		(*c)++;
// 	}
// }

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	index;

	index = 0;
	while (s[index])
	{
		f(index, &s[index]);
		index++;
	}
}
