/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 12:40:03 by vbaudot           #+#    #+#             */
/*   Updated: 2018/01/02 09:34:07 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execute(char **args, char ***envp)
{
	int			i;
	t_builtins	*tab;

	if (!(tab = (t_builtins*)malloc(5 * sizeof(t_builtins))))
		exit(EXIT_FAILURE);
	init_builtins(&tab);
	if (args[0] == NULL)
		return (1);
	i = -1;
	if (ft_strcmp(args[0], "setenv") == 0)
		return (mini_setenv(args, envp));
	if (ft_strcmp(args[0], "unsetenv") == 0)
		return (mini_unsetenv(args, envp));
	if (ft_strcmp(args[0], "cd") == 0)
		return (mini_cd(args, envp));
	while (tab[++i].str)
		if (ft_strcmp(args[0], tab[i].str) == 0)
			return (tab[i].f(args, *envp));
	free(tab);
	return (launch(args, *envp));
}
