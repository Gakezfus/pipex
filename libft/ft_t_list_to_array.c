/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_t_list_to_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkan <elkan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 18:48:03 by elkan             #+#    #+#             */
/*   Updated: 2026/01/04 20:06:56 by elkan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

void	*ft_t_list_to_array(t_list *list, size_t content_size)
{
	int		list_len;
	void	*to_return;
	int		index;

	if (list == NULL)
		return (NULL);
	list_len = ft_lstsize(list);
	to_return = malloc(list_len * content_size);
	index = 0;
	while (list)
	{
		ft_memcpy(to_return + index, list->content, content_size);
		list = list->next;
		index += content_size;
	}
	return (to_return);
}
