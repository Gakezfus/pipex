/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prtuint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elkan Choo <echoo@42mail.sutd.edu.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 13:55:49 by Elkan Choo        #+#    #+#             */
/*   Updated: 2025/12/01 17:04:48 by Elkan Choo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <unistd.h>
#include <stdlib.h>

int	ft_prtuint(unsigned int n, int *count)
{
	int		strlen;
	char	*s;
	int		to_return;

	strlen = 0;
	to_return = 0;
	s = ft_utoa(n);
	while (s[strlen] && to_return >= 0)
	{
		to_return = write(1, s + strlen, 1);
		if (to_return >= 0)
			strlen++;
	}
	free(s);
	(*count) += strlen;
	return (to_return);
}
