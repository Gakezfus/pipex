/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkan <elkan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:16:20 by Elkan Choo        #+#    #+#             */
/*   Updated: 2026/01/19 01:06:42 by elkan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>

typedef struct pararms
{
	int		file1_fd;
	int		file2_fd;
	int		error;
	int		here_doc;
	int		cmd_count;
	int		(*pipes)[2];
	char	*cmd_1;
	char	*cmd_2;
	char 	**envp;
	pid_t	*cmd_pid;
	pid_t	last_cmd_status;
}	t_pars;

// from pipex.c
char	**cmd_array(char *cmd, int (is_sep)(char), char *path, char *cmd_word);

// from get_path.c
char	*get_path(char *cmd, char *envp[]);

// from pipex_utils.c
char	*first_word(char *str, int (is_sep)(char));
int		is_sep(char c);
int		open_file1(char *argv[], t_pars *pars);
int		open_file2(char *argv[], t_pars *pars);
void	free_all(char *path, char **cmds, char *cmd_word, t_pars *pars);

// from get_heredoc.c
int		get_heredoc(char *limiter);

// from commands.c
pid_t	first_cmd(char *cmd, int read, int write, t_pars *pars);
pid_t	command(char *cmd, int read[2], int write, t_pars *pars);
void	other_commands(char *argv[], t_pars *pars);

#endif
