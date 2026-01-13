/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoo <echoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:12:07 by echoo             #+#    #+#             */
/*   Updated: 2025/11/24 15:50:14 by echoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #include <ctype.h>
// #include <stdio.h>

// int	ft_isalpha(int c);

// int	main(void)
// {
// 	int x = ft_isalpha('Z');
// 	printf("%i\n", x);
// }

int	ft_isalpha(int c)
{
	if ((65 <= c && c <= 90) || (97 <= c && c <= 122))
	{
		return (c);
	}
	return (0);
}
