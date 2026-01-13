/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoo <echoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 19:20:25 by echoo             #+#    #+#             */
/*   Updated: 2025/11/26 14:41:56 by echoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>
#include <stdio.h>

static int	b(t_list **tr, t_list *lst, void *(*f)(void *), void (*d)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*to_return;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	to_return = malloc(sizeof(t_list));
	if (to_return == NULL)
		return (NULL);
	if (b(&to_return, lst, f, del))
		return (NULL);
	return (to_return);
}

static int	b(t_list **tr, t_list *lst, void *(*f)(void *), void (*d)(void *))
{
	t_list	*tr_cpy;

	tr_cpy = *tr;
	while (lst)
	{
		tr_cpy->next = NULL;
		tr_cpy->content = f(lst->content);
		if (lst->next && tr_cpy->content)
		{
			tr_cpy->next = malloc(sizeof(t_list));
		}
		if ((lst->next && tr_cpy->next == NULL) || tr_cpy->content == NULL)
		{
			ft_lstclear(tr, d);
			return (1);
		}
		tr_cpy = tr_cpy->next;
		lst = lst->next;
	}
	return (0);
}
