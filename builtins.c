/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 12:38:15 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/28 14:11:59 by vbaudot          ###   ########.fr       */
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
	tmp[0].f = mini_help;
	tmp[1].f = mini_exit;
	tmp[2].f = mini_cd;
	tmp[3].f = NULL;
}

static void	ft_init_tab_char(t_builtins **tab)
{
	t_builtins *tmp;

	tmp = *tab;
	tmp[0].str = "help";
	tmp[1].str = "exit";
	tmp[2].str = "cd";
	tmp[3].str = 0;
}

void		init_builtins(t_builtins **tab)
{
	ft_init_tab_fc(tab);
	ft_init_tab_char(tab);
}
