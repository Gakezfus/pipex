/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoo <echoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:49:51 by echoo             #+#    #+#             */
/*   Updated: 2025/11/26 18:35:18 by echoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>
// #include <stdio.h>

// char		*ft_itoa(int n);

// int	main(void)
// {
// 	printf("%s\n", ft_itoa(-2147483648));
// }

static int	ft_d_count(int n);

char	*ft_itoa(int n)
{
	int		dc;
	int		index;
	int		neg;
	char	*to_return;

	dc = ft_d_count(n);
	neg = 0;
	if (n < 0)
		neg = 1;
	to_return = malloc(dc + neg + 1);
	if (to_return == NULL)
		return (NULL);
	if (neg)
		to_return[0] = '-';
	index = 0;
	while (index < dc)
	{
		to_return[dc - 1 + neg - index++] = ((n % 10) * (neg * -2 + 1)) + '0';
		n /= 10;
	}
	to_return[dc + neg] = '\0';
	return (to_return);
}

static int	ft_d_count(int n)
{
	int	dup;
	int	digit_count;

	if (n == 0)
		return (1);
	digit_count = 0;
	dup = n;
	while (dup)
	{
		dup /= 10;
		digit_count++;
	}
	return (digit_count);
}
