/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoo <echoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 19:14:44 by echoo             #+#    #+#             */
/*   Updated: 2025/11/24 15:50:29 by echoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h>
// #include <stdio.h>
// #include <string.h>

// size_t	ft_strlen(char *str);

// int	main(int argc, char *argv[])
// {
// 	if (argc != 2)
// 	{
// 		return (1);
// 	}

// 	printf("%li\n", strlen(argv[1]));
// 	printf("%li\n", ft_strlen(argv[1]));
// }

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}
