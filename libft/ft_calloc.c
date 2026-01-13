/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elkan Choo <echoo@42mail.sutd.edu.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:50:02 by echoo             #+#    #+#             */
/*   Updated: 2025/12/26 14:51:32 by Elkan Choo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

void	*ft_calloc(size_t nmemb, size_t size);

// int	main(void)
// {
// 	void *str = calloc(0, 0);
// 	free (str);
// 	// for (int i = 0; i < 2 * 3; i++)
// 	// {
// 	// 	if (!str[i])
// 	// 	{
// 	// 		printf("%c\n", '0');
// 	// 	}
// 	// 	else
// 	// 		printf("%c\n", str[i]);
// 	// }
// }

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*to_return;
	size_t			nmemb_index;
	size_t			total_mem;

	if (!nmemb || !size)
		return (malloc(0));
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	total_mem = nmemb * size;
	to_return = malloc(total_mem);
	if (to_return == NULL)
		return (NULL);
	nmemb_index = 0;
	while (nmemb_index < total_mem)
	{
		to_return[nmemb_index] = 0;
		nmemb_index++;
	}
	return ((void *)to_return);
}
