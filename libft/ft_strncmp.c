/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoo <echoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 17:43:58 by echoo             #+#    #+#             */
/*   Updated: 2025/11/24 15:50:30 by echoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h>
// #include <stdio.h>
// #include <string.h>

// int ft_strncmp(const char *s1, const char *s2, size_t n);

// int	main(void)
// {
// 	int	v = 2;
// 	char *x = "ABa";
// 	char *y = "AB7";

// 	printf("%i\n", ft_strncmp(x, y, v));
// 	printf("%i\n", strncmp(x, y, v));
// }

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	count;

	count = 0;
	while ((s1[count] != '\0' || s2[count] != '\0') && count < n)
	{
		if (!(s1[count] == s2[count]))
			return (s1[count] - s2[count]);
		count++;
	}
	return (0);
}
