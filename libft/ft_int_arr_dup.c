/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_arr_dup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elkan Choo <echoo@42mail.sutd.edu.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 17:24:17 by Elkan Choo        #+#    #+#             */
/*   Updated: 2025/12/26 18:18:59 by Elkan Choo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h>
#include <stdlib.h>

int	*ft_int_arr_dup(const int *i, size_t len)
{
	int		*dup;
	size_t	index;

	index = 0;
	dup = malloc(len);
	while (index < len)
	{
		dup[index] = i[index];
		index++;
	}
	return (dup);
}
