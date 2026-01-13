/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkan <elkan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:44:31 by elkan             #+#    #+#             */
/*   Updated: 2026/01/08 16:44:31 by elkan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*copy;
	t_list	*nxt;

	if (lst == NULL || *lst == NULL || del == NULL)
		return ;
	copy = *lst;
	while (copy != NULL)
	{
		nxt = copy->next;
		ft_lstdelone(copy, del);
		copy = nxt;
	}
	*lst = NULL;
}
