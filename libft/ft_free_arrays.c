/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_arrays.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkan <elkan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 12:39:51 by elkan             #+#    #+#             */
/*   Updated: 2026/01/10 16:35:13 by elkan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_free_arrays(void **array)
{
	size_t	index;

	if (array == NULL)
		return ;
	index = 0;
	while (array[index])
	{
		free(array[index]);
		index++;
	}
	free(array);
}
