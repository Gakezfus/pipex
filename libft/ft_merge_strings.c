/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_strings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elkan Choo <echoo@42mail.sutd.edu.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 18:13:03 by elkan             #+#    #+#             */
/*   Updated: 2026/01/14 15:18:31 by Elkan Choo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

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
