/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoo <echoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:12:42 by echoo             #+#    #+#             */
/*   Updated: 2025/11/24 15:50:18 by echoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #include <ctype.h>
// #include <stdio.h>

// int	ft_isdigit(int c);

// int	main(void)
// {
// 	int x = isdigit(58);
// 	printf("%i\n", x);
// }

int	ft_isdigit(int c)
{
	if (48 <= c && c <= 57)
	{
		return (c);
	}
	return (0);
}
