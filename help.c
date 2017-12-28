/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 12:41:02 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/28 14:09:58 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int mini_help(char **args)
{
	int i;
	t_builtins *tab;

	(void)args;
	printf("Stephen Brennan's LSH\n");
	printf("Type program names and arguments, and hit enter.\n");
	printf("The following are built in:\n");
	if (!(tab = (t_builtins*)malloc(4 * sizeof(t_builtins))))
		exit(EXIT_FAILURE);
	init_builtins(&tab);
	if (args[0] == NULL)
		return 1;
	i = -1;
	while (tab[++i].str)
		putf("  %s\n", tab[i].str);
	free(tab);
	printf("Use the man command for information on other programs.\n");
	return 1;
}
