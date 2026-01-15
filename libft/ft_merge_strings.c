/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_strings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkan <elkan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 18:13:03 by elkan             #+#    #+#             */
/*   Updated: 2026/01/15 18:11:48 by elkan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>
#include <stdarg.h>

int	ft_merge_strings(char **str_1, char *str_2)
{
	char	*dup;
	int		str_1_len;
	int		str_2_len;

	if (*str_1 == NULL || str_2 == NULL)
		return (1);
	str_1_len = ft_strlen(*str_1);
	str_2_len = ft_strlen(str_2);
	dup = malloc(str_1_len + str_2_len + 1);
	if (dup == NULL)
		return (1);
	ft_strlcpy(dup, *str_1, str_1_len + 1);
	ft_strlcpy(dup + str_1_len, str_2, str_2_len + 1);
	free (*str_1);
	*str_1 = dup;
	return (0);
}

int	ft_merge_strings_var(char **str_1, int str_count, ...)
{
	char	*dup;
	char	*to_add[10];
	int		strlen;
	int		index;
	va_list	ap;

	if (str_count > 10)
		return (1);
	va_start(ap, str_count);
	strlen = ft_strlen(*str_1);
	index = 0;
	while (index < str_count)
	{
		to_add[index] = va_arg(ap, char *);
		strlen += ft_strlen(to_add[index++]);
	}
	dup = malloc(strlen + 1);
	if (dup == NULL)
		return (1);
	ft_strlcpy(dup, *str_1, ft_strlen(*str_1) + 1);
	index = 0;
	while (index < str_count)
		ft_strlcat(dup, to_add[index++], strlen + 1);
	return (va_end(ap), free(*str_1), *str_1 = dup, 0);
}
