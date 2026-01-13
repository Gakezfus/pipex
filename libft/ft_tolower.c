/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoo <echoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:55:05 by echoo             #+#    #+#             */
/*   Updated: 2025/11/24 15:50:34 by echoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int	ft_tolower(int c);

// #include <stdio.h>
// #include <ctype.h>

// int	main(void)
// {
// 	int	x = 'g';

// 	printf("%c\n", ft_tolower(x));
// 	printf("%c\n", tolower(x));
// }

int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
	{
		c += ('a' - 'A');
	}
	return (c);
}
