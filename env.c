/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 16:26:47 by vbaudot           #+#    #+#             */
/*   Updated: 2018/01/03 15:28:34 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

static int	help_norm(char ***c_env, char ***setenv, int x, char **args)
{
	int i;

	i = 0;
	while (args[++i])
		if (ft_strcmp(args[i], "env") == 0)
			return (mini_env(&args[i], *c_env));
		else if (has_equal_sign(args[i], &x) == 1)
		{
			if (!(*setenv = (char **)malloc(sizeof(char *) * (4))))
				return (1);
			(*setenv)[3] = 0;
			(*setenv)[0] = ft_strdup("setenv");
			(*setenv)[1] = ft_strsub(args[i], 0, x);
			(*setenv)[2] = ft_strsub(args[i], x + 1,
				ft_strlen(args[i]) - (x + 1));
			mini_setenv(*setenv, c_env);
			x = -1;
			while ((*setenv)[++x])
				free((*setenv)[x]);
			free(*setenv);
		}
		else
			launch(&args[i], *c_env);
	return (1);
}

static int	help_norm_2(char ***c_env, char ***setenv, int x, char **args)
{
	int	i;

	i = -1;
	while ((*c_env)[++i])
		free((*c_env)[i]);
	free((*c_env));
	if (!(*c_env = (char **)malloc(sizeof(char *))))
		return (1);
	(*c_env)[0] = 0;
	if (args[1])
		return (help_norm(c_env, setenv, x, &args[1]));
	return (1);
}

int			mini_env(char **args, char **env)
{
	int		x;
	char	**c_env;
	char	**setenv;

	x = 0;
	while (env[x])
		x++;
	if (!(c_env = (char **)malloc(sizeof(char *) * (x + 1))))
		return (1);
	c_env[x] = 0;
	x = -1;
	while (env[++x])
	{
		c_env[x] = ft_strdup(env[x]);
		free(env[x]);
	}
	free(env);
	x = 0;
	if (!args[1])
		print_env(c_env);
	if (ft_strcmp(args[1], "-i") == 0)
		return (help_norm_2(&c_env, &setenv, x, args));
	else if (args[1])
		return (help_norm(&c_env, &setenv, x, args));
	x = -1;
	while (c_env[++x])
		free(c_env[x]);
	free(c_env);
	return (1);
}
