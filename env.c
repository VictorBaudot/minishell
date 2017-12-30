/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 16:26:47 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/30 15:34:53 by vbaudot          ###   ########.fr       */
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
	int i;
	int j;
	char *tmp;
	char *path;

	if (!args[1] || ft_strcmp(args[1], "") == 0)
		return (print_env(env));
	if (args[2])
	{
		ft_putendl("setenv: Too many arguments");
		return (1);
	}
	tmp = ft_strdup(ft_getenv(env, args[1]));
	ft_putendl(tmp);
	if (ft_strcmp(args[1], "PATH") == 0)
	{
		i = -1;
		while (42)
		{
			j = ++i;
			while (tmp[i])
			{
				if (tmp[i] == ':')
					break ;
				i++;
			}
			if (!tmp[i])
				break ;
			path = ft_strsub(tmp, j, (i - j));
			if (access(path, F_OK) == 0)
			{
				putf("%s is OK.\n", path);
				free(tmp);
				free(path);
				return (1);
			}
			else
				putf("%s is NOT OK.\n", path);
			free(path);
		}
	}
	free(tmp);
	return (1);
}

int	mini_env(char **args, char **env)
{
	if (!args[1])
		return (print_env(env));
	return (1);
}
