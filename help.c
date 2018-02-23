/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 12:41:02 by vbaudot           #+#    #+#             */
/*   Updated: 2018/02/23 11:55:55 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	mini_help(char **args)
{
	if (args[1])
	{
		ft_putendl("help: Too many arguments");
		return (1);
	}
	putf("Victor Baudot\'s Minishell\nType program names and arguments,");
	putf("and hit enter.\nThe following are built in:\n\n");
	if (args[0] == NULL)
		return (1);
	ft_putendl("->>  cd\n->>  setenv\n->>  unsetenv\n->>  env");
	ft_putendl("->>  echo\n->>  exit\n->>  help\n");
	putf("Use the man command for information on other programs.\n");
	return (1);
}
