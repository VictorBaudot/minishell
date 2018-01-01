/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 16:26:47 by vbaudot           #+#    #+#             */
/*   Updated: 2018/01/01 12:58:00 by vbaudot          ###   ########.fr       */
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

static int	has_equal_sign(char *str, int *x)
{
	int i;
	int y;

	i = -1;
	y = 0;
	while (str[++i])
	{
		if (str[i] == '=')
		{
			*x = y;
			return (1);
		}
		y++;
	}
	return (0);
}

int	mini_env(char **args, char **env)
{
	int x;
	char **setenv;

	x = 0;
	if (!args[1])
		return (print_env(env));
	if (ft_strcmp(args[1], "-i") == 0)
	{
		if (!(env = (char **)malloc(sizeof(char *))))
			return (1);
		env[0] = 0;
		if (args[2])
		{
			if (ft_strcmp(args[2], "env") == 0)
				return (mini_env(&args[2], env));
			else if (has_equal_sign(args[2], &x) == 1)
			{
				if (!(setenv = (char **)malloc(sizeof(char *) * (4))))
					return (1);
				setenv[3] = 0;
				setenv[0] = ft_strdup("setenv");
				setenv[1] = ft_strsub(args[2], 0, x);
				setenv[2] = ft_strsub(args[2], x + 1, ft_strlen(args[2]) - (x + 1));
				mini_setenv(setenv, &env);
				x = -1;
				while (setenv[++x])
					free(setenv[x]);
				free(setenv);
				if (ft_strcmp(args[3], "env") == 0)
					return (mini_env(&args[3], env));
				else if (args[3])
					return (launch(&args[3], env));
			}
			else
				return (launch(&args[2], env));
		}
	}
	else if (args[1])
	{
		if (ft_strcmp(args[1], "env") == 0)
			return (mini_env(&args[1], env));
		else if (has_equal_sign(args[1], &x) == 1)
		{
			if (!(setenv = (char **)malloc(sizeof(char *) * (4))))
				return (1);
			setenv[3] = 0;
			setenv[0] = ft_strdup("setenv");
			setenv[1] = ft_strsub(args[1], 0, x);
			setenv[2] = ft_strsub(args[1], x + 1, ft_strlen(args[1]) - (x + 1));
			mini_setenv(setenv, &env);
			x = -1;
			while (setenv[++x])
				free(setenv[x]);
			free(setenv);
			if (ft_strcmp(args[2], "env") == 0)
				return (mini_env(&args[2], env));
			else if (args[2])
				return (launch(&args[2], env));
		}
		else
			return (launch(&args[1], env));
	}
	return (1);
}
