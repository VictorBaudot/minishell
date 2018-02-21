/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 12:40:03 by vbaudot           #+#    #+#             */
/*   Updated: 2018/02/21 12:14:29 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execute(char **args, char ***envp)
{
	if (!args[0])
		return (1);
	if (ft_strcmp(args[0], "help") == 0)
		return (mini_help(args, *envp));
	else if (ft_strcmp(args[0], "exit") == 0)
		return (mini_exit(args, *envp));
	else if (ft_strcmp(args[0], "echo") == 0)
		return (mini_echo(args, *envp));
	return (launch(args, envp));
}
