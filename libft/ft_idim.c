/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_idim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkan <elkan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 13:29:07 by elkan             #+#    #+#             */
/*   Updated: 2025/12/29 13:45:05 by elkan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_idim(int x, int y)
{
	if (x > y)
		return ((unsigned int)x - (unsigned int)y);
	else
		return ((unsigned int)y - (unsigned int)x);
}
