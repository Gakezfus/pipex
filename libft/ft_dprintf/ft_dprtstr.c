/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprtstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elkan Choo <echoo@42mail.sutd.edu.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 12:59:14 by Elkan Choo        #+#    #+#             */
/*   Updated: 2026/01/16 12:59:14 by Elkan Choo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <unistd.h>

int	ft_dprtstr(int fd, char *s, int *count)
{
	int	strlen;
	int	to_return;

	if (s == NULL)
	{
		to_return = ft_dprtstr(fd, "(null)", count);
		return (to_return);
	}
	strlen = 0;
	to_return = 0;
	while (s[strlen] && to_return >= 0)
	{
		to_return = write(fd, s + strlen, 1);
		if (to_return >= 0)
			strlen++;
	}
	(*count) += strlen;
	return (to_return);
}
