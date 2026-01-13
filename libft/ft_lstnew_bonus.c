/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkan <elkan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:44:49 by elkan             #+#    #+#             */
/*   Updated: 2026/01/08 16:44:49 by elkan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

t_list	*ft_lstnew(void *content);

t_list	*ft_lstnew(void *content)
{
	t_list	*to_return;

	to_return = malloc(sizeof(t_list));
	if (to_return == NULL)
		return (NULL);
	to_return->content = content;
	to_return->next = NULL;
	return (to_return);
}
