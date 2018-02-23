/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 12:40:03 by vbaudot           #+#    #+#             */
/*   Updated: 2018/02/23 12:50:33 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execute(char **args, t_list **head)
{
//	int		x;
//	char	**envc;

	if (!args[0])
		return (1);
	if (ft_strcmp(args[0], "help") == 0)
		return (mini_help(args));
	else if (ft_strcmp(args[0], "exit") == 0)
		return (mini_exit(args));
	else if (ft_strcmp(args[0], "echo") == 0)
		return (mini_echo(args));
	else if (ft_strcmp(args[0], "unsetenv") == 0)
		return (mini_unsetenv(args, head));
	else if (ft_strcmp(args[0], "setenv") == 0)
		return (mini_setenv(args, head));/*
	else if (ft_strcmp(args[0], "cd") == 0)
		return (mini_cd(args, head));
	else if (ft_strcmp(args[0], "env") == 0)
	{
		x = 0;
		while ((*envp)[x])
			x++;
		if (!(envc = (char **)malloc(sizeof(char *) * (x + 1))))
			return (0);
		envc[x] = 0;
		x = -1;
		while ((*envp)[++x])
			envc[x] = ft_strdup((*envp)[x]);
		return (mini_env(args, envc));
	}*/
	return (launch(args, head));
}
