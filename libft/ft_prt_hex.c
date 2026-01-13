/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prt_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elkan Choo <echoo@42mail.sutd.edu.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 17:26:09 by Elkan Choo        #+#    #+#             */
/*   Updated: 2025/12/03 19:27:07 by Elkan Choo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>
#include <stdio.h>

int		ft_prtstr(char *s, int *count);
void	ft_utohextoa(uintptr_t num, char *string, char *base);

int	ft_prt_hex(char c, uintptr_t num, int *count)
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
	return (ft_prtstr(to_print, count));
}
