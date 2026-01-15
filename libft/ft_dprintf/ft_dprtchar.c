/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprtchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elkan Choo <echoo@42mail.sutd.edu.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 16:33:47 by echoo             #+#    #+#             */
/*   Updated: 2025/12/01 11:36:37 by Elkan Choo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdarg.h>
#include <unistd.h>

int	ft_dprtchar(int fd, char c, va_list *ap, int *count)
{
	char	arg;
	int		tr;

	arg = '%';
	if (c == 'c')
		arg = va_arg(*ap, int);
	tr = write(fd, &arg, 1);
	if (tr >= 0)
		(*count)++;
	return (tr);
}
