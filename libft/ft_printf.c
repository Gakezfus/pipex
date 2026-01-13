/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elkan Choo <echoo@42mail.sutd.edu.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 13:43:05 by echoo             #+#    #+#             */
/*   Updated: 2025/12/01 17:24:03 by Elkan Choo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

// int		ft_printf(const char *s, ...);

// int	main(void)
// {
// 	char *str = NULL;

// 	int	printf_return = printf("Hello world %%;
// 	int	ft_printf_return = ft_printf("Hello world %%);

// 	printf("%i\n", printf_return);
// 	printf("%i\n", ft_printf_return);
// }

static int	ft_print_special(va_list *ap, int *count, char c);

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, s);
	while (*s)
	{
		if (*s != '%')
		{
			if (write(1, s, 1) < 0)
				return (-1);
			count++;
		}
		else if (*(s + 1))
		{
			s++;
			if (ft_print_special(&ap, &count, *s) < 0)
				return (-1);
		}
		s++;
	}
	va_end(ap);
	return (count);
}

static int	ft_print_special(va_list *ap, int *count, char c)
{
	if (c == 'c' || c == '%')
		return (ft_prtchar(c, ap, count));
	if (c == 's')
		return (ft_prtstr(va_arg(*ap, char *), count));
	if (c == 'x' || c == 'X')
		return (ft_prt_hex(c, va_arg(*ap, unsigned int), count));
	if (c == 'd' || c == 'i')
		return (ft_prtnbr(va_arg(*ap, int), count));
	if (c == 'u')
		return (ft_prtuint(va_arg(*ap, unsigned int), count));
	if (c == 'p')
		return (ft_prtptr(ap, count, c));
	return (-1);
}
