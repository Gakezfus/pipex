/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoo <echoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 19:37:42 by echoo             #+#    #+#             */
/*   Updated: 2025/11/24 15:50:11 by echoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <stdlib.h>

// int	ft_atoi(const char *str);

// int	main(void)
// {
// 	char *string = "  \t-2147483648";
// 	printf("%i\n", ft_atoi(string));
// 	printf("%i\n", atoi(string));
// }

int	ft_atoi(const char *str)
{
	int	negative;
	int	index;
	int	to_return;

	negative = -1;
	index = 0;
	while (str[index] == ' ' || ('\t' <= str[index] && str[index] <= '\r'))
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
		{
			negative = -negative;
		}
		index++;
	}
	to_return = 0;
	while (('0' <= str[index] && str[index] <= '9'))
	{
		to_return *= 10;
		to_return -= str[index] - '0';
		index++;
	}
	to_return *= negative;
	return (to_return);
}
