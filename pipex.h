/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkan <elkan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:16:20 by Elkan Choo        #+#    #+#             */
/*   Updated: 2026/01/17 17:00:25 by elkan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>

typedef struct pararms
{
	int		file1_fd;
	int		file2_fd;
	int		pip[2];
	int		error;
	pid_t	child1_pid;
	pid_t	child2_pid;
	pid_t	child_1_status;
	pid_t	child_2_status;
}	t_pars;

// from get_path.c
char	*get_path(char *cmd, char *envp[]);

// from pipex_utils.c
char	*first_word(char *str, int (is_sep)(char));
int		is_sep(char c);
int		open_file1(char *argv[]);
int		open_file2(char *argv[], t_pars *pars);
void	free_all(char *path, char **cmds, char *cmd_word);

#endif
