/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 15:20:06 by vbaudot           #+#    #+#             */
/*   Updated: 2018/01/01 17:53:55 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <sys/wait.h>
# include <unistd.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <stdio.h> // DELETE
# include <string.h> // DELETE
# include <signal.h>
# include "libft.h"

# define YEL "\x1b[33m"
# define BLU "\x1b[34m"
# define RED "\x1b[31m"
# define NC "\x1b[0m"
# define MAG "\x1b[35m"
# define CYA "\x1b[36m"
# define GRE "\x1b[32m"
# define BOL "\x1b[1m"
# define B_BLA "\x1b[90m"
# define B_R  "\x1b[91m"
# define B_G  "\x1b[92m"
# define B_Y "\x1b[93m"
# define B_BLU  "\x1b[94m"
# define B_MA  "\x1b[95m"
# define B_CY "\x1b[96m"
# define B_WH  "\x1b[97m"

typedef struct	s_builtins
{
	char		*str;
	int			(*f)(char **, char **);
}				t_builtins;

int				print_env(char **env);
int				mini_echo(char **args, char **env);
int				mini_cd(char **args, char ***env);
int				mini_setenv(char **args, char ***env);
int				mini_unsetenv(char **args, char ***env);
int				mini_env(char **args, char **env);
int				mini_exit(char **args, char **env);
int				mini_help(char **args, char **env);
char			*ft_path(char **env, char *path);
char			*ft_getenv(char **env, char *elem);
void			init_builtins();
int				execute(char **args, char ***env);
int				launch(char **args, char **env);
void			print_usage(void);
void			ft_error(void);

#endif
