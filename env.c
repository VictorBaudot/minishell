/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 16:26:47 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/30 11:33:28 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int print_env(char **env)
{
	int i;

	i = -1;
	while (env[++i])
		putf("%s\n", env[i]);
	return (1);
}

int	mini_setenv(char **args, char **env)
{
	int i;
	char **tmp;

	i = -1;
	if (!args[1])
		return (print_env(env));
	if (!args[2])
		args[2] = "";
	if (args[3])
	{
		ft_putendl("setenv: Too many arguments");
		return (1);
	}
	while (env[++i]){}
	if (!(tmp = (char **)malloc(sizeof(char *) * (i + 2))))
		exit(EXIT_FAILURE);
	tmp[i + 1] = 0;
	tmp[i] = ft_str3join(args[1], "=", args[2]);
	i = -1;
	while (env[++i])
		tmp[i] = ft_strdup(env[i]);
	print_env(tmp);
	return (1);
}

int	mini_unsetenv(char **args, char **env)
{
	(void)args;
	(void)env;
	putf("Not done yet.\n");
	return (1);
}

int	mini_env(char **args, char **env)
{
	if (!args[1])
		return (print_env(env));
	return (1);
}
