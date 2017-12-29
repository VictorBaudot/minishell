/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 12:38:15 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/29 16:29:09 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int mini_exit(char **args)
{
	(void)args;
	return 0;
}

static void	ft_init_tab_fc(t_builtins **tab)
{
	t_builtins *tmp;

	tmp = *tab;
	tmp[0].f = mini_echo;
	tmp[1].f = mini_cd;
	tmp[2].f = mini_setenv;
	tmp[3].f = mini_unsetenv;
	tmp[4].f = mini_env;
	tmp[5].f = mini_exit;
	tmp[6].f = mini_help;
	tmp[7].f = NULL;
}

static void	ft_init_tab_char(t_builtins **tab)
{
	t_builtins *tmp;

	tmp = *tab;
	tmp[0].str = "echo";
	tmp[1].str = "cd";
	tmp[2].str = "setenv";
	tmp[3].str = "unsetenv";
	tmp[4].str = "env";
	tmp[5].str = "exit";
	tmp[6].str = "help";
	tmp[7].str = 0;
}

void		init_builtins(t_builtins **tab)
{
	ft_init_tab_fc(tab);
	ft_init_tab_char(tab);
}
