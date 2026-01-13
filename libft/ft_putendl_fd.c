/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoo <echoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:02:34 by echoo             #+#    #+#             */
/*   Updated: 2025/11/24 17:05:56 by echoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <unistd.h>

// void	ft_putendl_fd(char *s, int fd);

// int	main(void)
// {
// 	char	*str = "Hello, world";
// 	ft_putendl_fd(str, 1);
// }

void	ft_putendl_fd(char *s, int fd)
{
	int	strlen;

	strlen = 0;
	while (s[strlen])
	{
		strlen++;
	}
	write(fd, s, strlen);
	write(fd, "\n", 1);
}
