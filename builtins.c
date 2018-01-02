/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 12:38:15 by vbaudot           #+#    #+#             */
/*   Updated: 2018/01/02 09:33:45 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			mini_exit(char **args, char **env)
{
	(void)env;
	ft_putendl("exit");
	if (args[1])
	{
		ft_putendl("exit: Too many arguments");
		return (1);
	}
	return (0);
}

static void	ft_init_tab_fc(t_builtins **tab)
{
	t_builtins *tmp;

	tmp = *tab;
	tmp[0].f = mini_echo;
	tmp[1].f = mini_env;
	tmp[2].f = mini_exit;
	tmp[3].f = mini_help;
	tmp[4].f = NULL;
}

static void	ft_init_tab_char(t_builtins **tab)
{
	t_builtins *tmp;

	tmp = *tab;
	tmp[0].str = "echo";
	tmp[1].str = "env";
	tmp[2].str = "exit";
	tmp[3].str = "help";
	tmp[4].str = 0;
}

void		init_builtins(t_builtins **tab)
{
	ft_init_tab_fc(tab);
	ft_init_tab_char(tab);
}
