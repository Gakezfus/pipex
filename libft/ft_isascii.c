/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoo <echoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:12:34 by echoo             #+#    #+#             */
/*   Updated: 2025/11/24 15:50:17 by echoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #include <ctype.h>
// #include <stdio.h>

// int	ft_isascii(int c);

// int	main(int argc, char *argv[])
// {
// 	if (argc != 2)
// 	{
// 		printf("Add char to be checked\n");
// 		return (1);
// 	}
// 	int x = argv[1][0];
// 	printf("%i\n", x);
// 	printf("%i\n", isascii(128));
// 	printf("%i\n", ft_isascii(128));
// }

int	ft_isascii(int c)
{
	if (0 <= c && c <= 127)
	{
		return (1);
	}
	return (0);
}
