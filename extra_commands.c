/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkan <elkan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 18:58:04 by elkan             #+#    #+#             */
/*   Updated: 2026/01/18 19:13:57 by elkan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex.h"

#include <stdlib.h>
#include <unistd.h>

void	setup_extra(int argc, char *argv, char *pars)
{
	int	index;

	extra_count = argc - pars->here_doc - 5;
	if (!extra_count)
		return ;
	pars->extra_pipes = ft_calloc(extra_count, sizeof(int[2]));
	pars->extra_pid = ft_calloc(extra_count, sizeof(pid_t));
	pars->extra_status = ft_calloc(extra_count, sizeof(pid_t));

}
