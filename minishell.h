/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 15:20:06 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/30 09:48:25 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> // DELETE
# include <string.h> // DELETE
# include "libft.h"

typedef struct	s_builtins
{
	char		*str;
	int			(*f)(char **, char **);
}				t_builtins;

int				mini_echo(char **args, char **env);
int				mini_cd(char **args, char **env);
int				mini_setenv(char **args, char **env);
int				mini_unsetenv(char **args, char **env);
int				mini_env(char **args, char **env);
int				mini_exit(char **args, char **env);
int				mini_help(char **args, char **env);
void			init_builtins();
int				execute(char **args, char **env);
int				launch(char **args);
void			print_usage(void);
void			ft_error(void);

#endif
