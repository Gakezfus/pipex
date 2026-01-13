/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elkan Choo <echoo@42mail.sutd.edu.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 16:26:20 by echoo             #+#    #+#             */
/*   Updated: 2025/11/30 19:56:23 by Elkan Choo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>
// #include <stdio.h>

// char		*ft_utoa(unsigned int n);

// int	main(void)
// {
// 	printf("%s\n", ft_utoa(4294967295));
// }

static int	ft_d_count(unsigned int n);

char	*ft_utoa(unsigned int n)
{
	int		dc;
	int		index;
	char	*to_return;

	dc = ft_d_count(n);
	to_return = malloc(dc + 1);
	if (to_return == NULL)
		return (NULL);
	index = 0;
	while (index < dc)
	{
		to_return[dc - 1 - index++] = (n % 10) + '0';
		n /= 10;
	}
	to_return[dc] = '\0';
	return (to_return);
}

static int	ft_d_count(unsigned int n)
{
	unsigned int	dup;
	int				digit_count;

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
