/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoo <echoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:12:13 by echoo             #+#    #+#             */
/*   Updated: 2025/11/26 16:56:11 by echoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h>
// #include <ctype.h>
// #include <stdio.h>

// int	ft_isalnum(int c);

// int	main(int argc, char *argv[])
// {
// 	if (argc != 2)
// 	{
// 		printf("Add char to be checked\n");
// 		return (1);
// 	}
// 	int x = argv[1][0];
// 	printf("%i\n", isalnum(x));
// 	printf("%i\n", ft_isalnum(x));
// }

int	ft_isalnum(int c)
{
	if ((ft_isalpha(c)) || ft_isdigit(c))
	{
		return (c);
	}
	return (0);
}
