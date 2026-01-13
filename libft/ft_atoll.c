/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elkan Choo <echoo@42mail.sutd.edu.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 10:55:58 by Elkan Choo        #+#    #+#             */
/*   Updated: 2025/12/24 10:56:01 by Elkan Choo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int	ft_atoll(const char *str)
{
	int				negative;
	int				index;
	long long int	to_return;

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
