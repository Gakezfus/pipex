/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoo <echoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 13:31:22 by echoo             #+#    #+#             */
/*   Updated: 2025/11/26 18:37:54 by echoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>
#include <unistd.h>

// void	ft_putnbr_fd(int n, int fd);

// int	main(void)
// {
// 	ft_putnbr_fd(1, 1);
// }

void	ft_putnbr_fd(int n, int fd)
{
	int		strlen;
	char	*s;

	strlen = 0;
	s = ft_itoa(n);
	while (s[strlen])
	{
		strlen++;
	}
	write(fd, s, strlen);
	free(s);
}
