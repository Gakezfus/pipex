/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoo <echoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:55:36 by echoo             #+#    #+#             */
/*   Updated: 2025/11/26 13:03:51 by echoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <unistd.h>

// void	ft_putchar_fd(char c, int fd);

// int	main(void)
// {
// 	ft_putchar_fd('c', 1);
// }

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
