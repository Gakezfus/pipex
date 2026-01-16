/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprtnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elkan Choo <echoo@42mail.sutd.edu.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 12:58:53 by Elkan Choo        #+#    #+#             */
/*   Updated: 2026/01/16 12:58:53 by Elkan Choo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <unistd.h>
#include <stdlib.h>

int	ft_dprtnbr(int fd, int n, int *count)
{
	int		strlen;
	char	*s;
	int		to_return;

	strlen = 0;
	to_return = 0;
	s = ft_itoa(n);
	while (s[strlen] && to_return >= 0)
	{
		to_return = write(fd, s + strlen, 1);
		if (to_return >= 0)
			strlen++;
	}
	free(s);
	(*count) += strlen;
	return (to_return);
}
