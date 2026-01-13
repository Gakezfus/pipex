/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoo <echoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:49:40 by echoo             #+#    #+#             */
/*   Updated: 2025/11/26 19:45:32 by echoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>
#include <stdio.h>

char		**ft_split(char const *str, char c);
static int	ft_count_str(char const *str, char c);
static int	ft_all_str(char **tr, char const *str, char c, int str_count);
static int	ft_add_str(char **tr, char const *str, char c, int wc);
static void	free_all(char **to_return);

// int	main(void)
// {
// 	char **array;

// 	array = ft_split("Tripouille", ' ');
// 	for (int i = 0; i < 2; i++)
// 	{
// 		printf("%s\n", array[i]);
// 	}
// 	(void)array;
// }

char	**ft_split(char const *str, char c)
{
	char	**to_return;
	int		str_count;

	if (!str || !*str)
		return (NULL);
	str_count = ft_count_str(str, c);
	to_return = malloc((str_count + 1) * sizeof(char *));
	if (to_return == NULL)
		return (NULL);
	if (ft_all_str(to_return, str, c, str_count))
		return (free_all(to_return), NULL);
	return (to_return);
}

static void	free_all(char **to_return)
{
	static int	index = 0;

	while (to_return[index])
	{
		free(to_return[index]);
		index++;
	}
	free(to_return);
}

static int	ft_all_str(char **tr, char const *str, char c, int str_count)
{
	int	str_index;
	int	sep_found;
	int	wc;

	str_index = 0;
	sep_found = 1;
	wc = 0;
	while (wc < str_count)
	{
		if (str[str_index] == c)
		{
			sep_found = 1;
		}
		else if (sep_found)
		{
			if (ft_add_str(tr, &str[str_index], c, wc))
				return (1);
			wc++;
			sep_found = 0;
		}
		str_index++;
	}
	tr[wc] = NULL;
	return (0);
}

static int	ft_add_str(char **tr, char const *str, char c, int wc)
{
	int	str_index;
	int	str_len;

	str_len = 0;
	str_index = 0;
	while (str[str_index] && str[str_index] != c)
	{
		str_len++;
		str_index++;
	}
	tr[wc] = malloc ((str_len + 1) * sizeof(char));
	if (tr[wc] == NULL)
		return (1);
	str_index = 0;
	while (str_index < str_len)
	{
		tr[wc][str_index] = str[str_index];
		str_index++;
	}
	tr[wc][str_index] = '\0';
	return (0);
}

static int	ft_count_str(char const *str, char c)
{
	int	str_index;
	int	wc;
	int	sep_found;

	wc = 0;
	str_index = 0;
	sep_found = 1;
	while (str[str_index])
	{
		if (str[str_index] == c)
			sep_found = 1;
		else if (sep_found)
		{
			wc++;
			sep_found = 0;
		}
		str_index++;
	}
	return (wc);
}
