/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 12:40:03 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/30 15:26:57 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int execute(char **args, char **envp)
{
	int i;
	t_builtins *tab;

	if (!(tab = (t_builtins*)malloc(8 * sizeof(t_builtins))))
		exit(EXIT_FAILURE);
	init_builtins(&tab);
	if (args[0] == NULL)
		return (1);
	i = -1;
	while (tab[++i].str)
		if (strcmp(args[0], tab[i].str) == 0)
			return (tab[i].f(args, envp));
	free(tab);
	return (launch(args, envp));
}
