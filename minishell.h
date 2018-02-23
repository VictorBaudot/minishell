/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 15:20:06 by vbaudot           #+#    #+#             */
/*   Updated: 2018/02/23 16:23:26 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <sys/wait.h>
# include <unistd.h>
# include <sys/stat.h>
# include <stdlib.h>
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

int				list_len(t_list **head);
void			ft_lsterase(t_list **head);
t_list			*create_list_from_env(char **env);
char			**create_env_from_list(t_list **head);
void			ft_lstdelthis(t_list **head, char *str);
int				too_many_args(char *cmd);
int				check_env(char **args, t_list **head, int *i);
int				print_env(t_list **head);
int				mini_echo(char **args);
int				mini_cd(char **args, t_list **head);
int				mini_setenv(char **args, t_list **head);
int				mini_unsetenv(char **args, t_list **head);
int				mini_env(char **args, t_list **head);
int				mini_exit(char **args);
int				mini_help(char **args);
char			*ft_path(t_list **head, char *path);
char			*ft_getenv(t_list **head, char *elem);
int				execute_env(char **args, t_list **head);
int				execute(char **args, t_list **head);
int				launch(char **args, t_list **head);
void			print_usage(void);
void			ft_error(void);

#endif
