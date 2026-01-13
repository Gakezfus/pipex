/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoo <echoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:49:33 by echoo             #+#    #+#             */
/*   Updated: 2025/11/24 15:50:26 by echoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>
// #include <stdio.h>
// #include <string.h>

// char	*ft_strdup(const char *s);

// int	main(void)
// {
// 	char *str = "Hello world!";
// 	char *dup;

// 	dup = strdup(str);
// 	printf("%s\n", dup);
// 	free(dup);
// }

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	strlen;
	size_t	index;

	strlen = ft_strlen(s);
	dup = malloc(strlen + 1);
	index = 0;
	while (index < strlen)
	{
		dup[index] = s[index];
		index++;
	}
	dup[index] = '\0';
	return (dup);
}
