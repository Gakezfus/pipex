/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkan <elkan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:16:20 by Elkan Choo        #+#    #+#             */
/*   Updated: 2026/01/15 18:15:20 by elkan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

// from get_path.c
char	*get_path(char *cmd, char *envp[]);

// from pipex_utils.c
char	*first_word(char *str, int (is_sep)(char));
int		is_sep(char c);
int		open_file1(char *argv[], int *fail);
int		open_file2(char *argv[], int *error, int *fail);

#endif
