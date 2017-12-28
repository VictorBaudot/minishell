/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 12:41:02 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/28 14:41:47 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int mini_help(char **args)
{
	int i;
	t_builtins *tab;

	(void)args;
	putf("Victor Baudot\'s Minishell\nType program names and arguments,");
	putf("and hit enter.\nThe following are built in:\n");
	if (!(tab = (t_builtins*)malloc(4 * sizeof(t_builtins))))
		exit(EXIT_FAILURE);
	init_builtins(&tab);
	if (args[0] == NULL)
		return 1;
	i = -1;
	while (tab[++i].str)
		putf("  %s\n", tab[i].str);
	free(tab);
	putf("Use the man command for information on other programs.\n");
	return 1;
}
