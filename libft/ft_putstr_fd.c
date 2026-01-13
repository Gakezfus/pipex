/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoo <echoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:59:13 by echoo             #+#    #+#             */
/*   Updated: 2025/11/26 12:56:35 by echoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <unistd.h>

void	ft_putstr_fd(char *s, int fd);

// int	main(void)
// {
// 	ft_putstr_fd("Hello world", 1);
// }

void	ft_putstr_fd(char *s, int fd)
{
	int	strlen;

	strlen = 0;
	while (s[strlen])
	{
		strlen++;
	}
	write(fd, s, strlen);
}
