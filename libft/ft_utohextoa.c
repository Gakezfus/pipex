/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utohextoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elkan Choo <echoo@42mail.sutd.edu.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 17:14:51 by echoo             #+#    #+#             */
/*   Updated: 2025/12/01 17:17:05 by Elkan Choo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdint.h>
// #include <stdio.h>

void	ft_utohextoa(uintptr_t num, char *string, char *base)
{
	unsigned int	count;
	uintptr_t		dup;
	unsigned int	digit_count;

	digit_count = 1;
	dup = num;
	while (dup / 16 > 0)
	{
		digit_count++;
		dup /= 16;
	}
	count = 0;
	while (count < digit_count)
	{
		{
			string[digit_count - count - 1] = base[num % 16];
			num /= 16;
		}
		count++;
	}
	string[count] = '\0';
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%s\n", ft_ultohextoa(0, "0123456789abcdef"));
// }
