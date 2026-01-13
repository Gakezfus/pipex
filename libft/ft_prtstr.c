/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prtstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elkan Choo <echoo@42mail.sutd.edu.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 13:53:32 by Elkan Choo        #+#    #+#             */
/*   Updated: 2025/12/01 17:17:17 by Elkan Choo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <unistd.h>

int	ft_prtstr(char *s, int *count)
{
	int	strlen;
	int	to_return;

	if (s == NULL)
	{
		to_return = ft_prtstr("(null)", count);
		return (to_return);
	}
	strlen = 0;
	to_return = 0;
	while (s[strlen] && to_return >= 0)
	{
		to_return = write(1, s + strlen, 1);
		if (to_return >= 0)
			strlen++;
	}
	(*count) += strlen;
	return (to_return);
}
