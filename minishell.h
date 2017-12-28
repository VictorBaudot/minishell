/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 15:20:06 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/28 14:08:13 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define LSH_TOK_BUFSIZE 64
# define LSH_TOK_DELIM " \t\r\n\a"
# define LSH_RL_BUFSIZE 1024

# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> // DELETE
# include <string.h> // DELETE
# include "libft.h"

typedef struct	s_builtins
{
	char		*str;
	int			(*f)(char **);
}				t_builtins;

int				mini_exit(char **args);
void			init_builtins();
int				mini_cd(char **args);
char			*read_line(void);
int				execute(char **args);
char			**split_line(char *line);
int				mini_help(char **args);
int				launch(char **args);
void			print_usage(void);
void			ft_error(void);

#endif
