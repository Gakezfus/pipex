/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prtptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elkan Choo <echoo@42mail.sutd.edu.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 19:36:38 by Elkan Choo        #+#    #+#             */
/*   Updated: 2025/12/01 17:24:33 by Elkan Choo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdarg.h>
#include <unistd.h>
#include <stdint.h>

int	ft_prt_hex(char c, uintptr_t num, int *count);
int	ft_prtstr(char *s, int *count);

int	ft_prtptr(va_list *ap, int *count, char c)
{
	int			to_return;
	uintptr_t	add;

	add = (uintptr_t)va_arg(*ap, void *);
	if (add == (uintptr_t) NULL)
	{
		to_return = ft_prtstr("(nil)", count);
		return (to_return);
	}
	to_return = write(1, "0x", 2);
	if (to_return < 0)
		return (to_return);
	*count += 2;
	to_return = ft_prt_hex(c, add, count);
	if (to_return < 0)
		return (to_return);
	return (0);
}
