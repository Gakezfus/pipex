/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoo <echoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:49:28 by echoo             #+#    #+#             */
/*   Updated: 2025/11/24 16:43:03 by echoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>
// #include <stdio.h>

// char	*ft_strjoin(char const *s1, char const *s2);

// int	main(void)
// {
// 	char *string = ft_strjoin("Hello ", "world");
// 	printf("%s\n", string);
// 	free(string);
// }

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	j_index;
	size_t	index;
	size_t	s1_strlen;
	size_t	s2_strlen;
	char	*to_return;

	s1_strlen = ft_strlen(s1);
	s2_strlen = ft_strlen(s2);
	to_return = malloc(s1_strlen + s2_strlen + 1);
	if (to_return == NULL)
		return (NULL);
	j_index = 0;
	index = 0;
	while (index < s1_strlen)
		to_return[j_index++] = s1[index++];
	index = 0;
	while (index < s2_strlen)
		to_return[j_index++] = s2[index++];
	to_return[j_index] = '\0';
	return (to_return);
}
