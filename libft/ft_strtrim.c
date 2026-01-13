/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elkan Choo <echoo@42mail.sutd.edu.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:49:05 by echoo             #+#    #+#             */
/*   Updated: 2025/12/26 14:47:56 by Elkan Choo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>
// #include <stdio.h>
// #include <strings.h>

// char	*ft_strtrim(char const *s1, char const *set);

// int	main(void)
// {
// 	char	*s1 = "   xxx   xxx";
// 	char	*set = " x";
// 	char	*trim = ft_strtrim(s1, set);
// 	printf("%s\n", trim);
// 	free(trim);
// }

static int	ft_totrim(char const *s1, char const *set, int dir);

char	*ft_strtrim(char const *s1, char const *set)
{
	int		mark[2];
	int		index[2];
	char	*to_return;

	mark[0] = ft_totrim(s1, set, 1);
	mark[1] = ft_totrim(s1, set, -1);
	ft_bzero(index, 2 * sizeof(int));
	if (mark[1] - mark[0] < 0)
		to_return = malloc(1);
	else
	{
		to_return = malloc(mark[1] - mark[0] + 2);
		if (to_return == NULL)
			return (NULL);
		while (s1[index[0]])
		{
			if (mark[0] <= index[0] && index[0] <= mark[1])
				to_return[index[1]++] = s1[index[0]];
			index[0]++;
		}
	}
	to_return[index[1]] = '\0';
	return (to_return);
}

static int	ft_totrim(char const *s1, char const *set, int dir)
{
	int	index[2];
	int	trim;

	if (dir > 0)
		index[0] = 0;
	else
		index[0] = ft_strlen(s1) - 1;
	trim = 1;
	while (((dir > 0 && s1[index[0]]) || (dir < 0 && index[0] > 0)) && trim)
	{
		trim = 0;
		index[1] = 0;
		while (set[index[1]])
		{
			if (s1[index[0]] == set[index[1]])
				trim = 1;
			index[1]++;
		}
		if (trim)
			index[0] += dir;
	}
	return (index[0]);
}
