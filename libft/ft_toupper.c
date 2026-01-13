/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoo <echoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:43:47 by echoo             #+#    #+#             */
/*   Updated: 2025/11/24 15:50:34 by echoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int	ft_toupper(int c);

// #include <stdio.h>
// #include <ctype.h>

// int	main(void)
// {
// 	int	x = 'A';

// 	printf("%c\n", ft_toupper(x));
// 	printf("%c\n", toupper(x));
// }

int	ft_toupper(int c)
{
	if (97 <= c && c <= 122)
	{
		c += ('A' - 'a');
	}
	return (c);
}
