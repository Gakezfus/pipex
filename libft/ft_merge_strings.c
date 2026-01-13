/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_strings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkan <elkan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 18:13:03 by elkan             #+#    #+#             */
/*   Updated: 2026/01/02 21:24:23 by elkan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

int	ft_merge_strings(char **str_1, char *str_2)
{
	char	*dup;
	int		str_1_len;
	int		str_2_len;

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
