/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_zero.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkan <elkan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 19:18:55 by elkan             #+#    #+#             */
/*   Updated: 2025/12/29 19:51:16 by elkan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdarg.h>

void	ft_set_zero(int num, ...)
{
	va_list	ap;
	int		index;
	int		*to_zero;

	index = 0;
	va_start(ap, num);
	while (index < num)
	{
		to_zero = va_arg(ap, int *);
		*to_zero = 0;
		index++;
	}
	va_end(ap);
}
