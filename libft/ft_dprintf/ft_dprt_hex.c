/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprt_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elkan Choo <echoo@42mail.sutd.edu.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 12:58:17 by Elkan Choo        #+#    #+#             */
/*   Updated: 2026/01/16 12:58:17 by Elkan Choo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>
#include <stdio.h>

int		ft_dprtstr(int fd, char *s, int *count);
void	ft_utohextoa(uintptr_t num, char *string, char *base);

int	ft_dprt_hex(int fd, char c, uintptr_t num, int *count)
{
	char			base[17];
	char			to_print[20];

	if (c == 'X')
	{
		ft_strlcpy(base, "0123456789ABCDEF", 17);
	}
	else
		ft_strlcpy(base, "0123456789abcdef", 17);
	ft_utohextoa(num, to_print, base);
	return (ft_dprtstr(fd, to_print, count));
}
