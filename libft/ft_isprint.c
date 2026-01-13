/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoo <echoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:12:46 by echoo             #+#    #+#             */
/*   Updated: 2025/11/24 15:50:19 by echoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #include <ctype.h>
// #include <stdio.h>

// int	ft_isprint(int c);

// int	main(int argc, char *argv[])
// {
// 	if (argc != 2)
// 	{
// 		printf("Add char to be checked\n");
// 		return (1);
// 	}
// 	int x = argv[1][0];
// 	printf("%i\n", x);
// 	printf("%i\n", isprint(31));
// 	printf("%i\n", ft_isprint(31));
// }

int	ft_isprint(int c)
{
	if (32 <= c && c <= 126)
	{
		return (c);
	}
	return (0);
}
