/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 13:25:54 by vbaudot           #+#    #+#             */
/*   Updated: 2018/02/20 13:39:09 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			var_dont_exist(int i, char **args, char ***env)
{
	char	**tmp;

	if (!(tmp = (char **)malloc(sizeof(char *) * (i + 1))))
		return (1);
	tmp[i] = 0;
	i = -1;
	while ((*env)[++i])
		tmp[i] = ft_strdup((*env)[i]);
	if (!(*env = (char **)malloc(sizeof(char *) * (i + 2))))
		return (1);
	(*env)[i + 1] = 0;
	(*env)[i] = ft_str3join(args[1], "=", args[2]);
	i = -1;
	while (tmp[++i])
		(*env)[i] = ft_strdup(tmp[i]);
	i = -1;
	while (tmp[++i])
		free(tmp[i]);
	free(tmp);
	return (1);
}

int			var_exist(int i, int flag, int len, char ***env)
{
	char	**tmp;
	int		j;

	if (!(tmp = (char **)malloc(sizeof(char *) * (len))))
		return (1);
	tmp[len - 1] = 0;
	j = -1;
	while ((*env)[++j])
	{
		if (j == flag)
			continue ;
		tmp[++i] = ft_strdup((*env)[j]);
	}
	if (!(*env = (char **)malloc(sizeof(char *) * (len))))
		return (1);
	(*env)[len - 1] = 0;
	i = -1;
	while (tmp[++i])
		(*env)[i] = ft_strdup(tmp[i]);
	i = -1;
	while (tmp[++i])
		free(tmp[i]);
	free(tmp);
	return (1);
}

int			mini_setenv(char **args, char ***env)
{
	int		i;
	int		flag;

	i = -1;
	if (!args[1])
		return (print_env(*env));
	else
		while (args[1][++i])
			if (args[1][i] == '=')
			{
				ft_putendl("minishell: setenv: Variable name is not valid.");
				return (1);
			}
	if (!args[2])
		args[2] = "";
	if (args[3])
		return (too_many_args("setenv"));
	i = 0;
	flag = check_env(args, env, &i);
	if (flag == i - 1)
		(*env)[i - 1] = ft_str3join(args[1], "=", args[2]);
	else
		return (var_dont_exist(i, args, env));
	return (1);
}

int			mini_unsetenv(char **args, char ***env)
{
	int		j;
	int		i;
	int		len;
	int		flag;

	if (!args[1])
		return (print_env(*env));
	j = 0;
	while (args[++j])
	{
		i = 0;
		if (ft_strcmp(args[j], "*") == 0)
		{
			*env = (char **)malloc(sizeof(char *));
			(*env)[0] = 0;
			return (1);
		}
		flag = check_env(&args[j - 1], env, &i);
		len = 0;
		while ((*env)[len])
			len++;
		if (flag == i - 1 && i != 0)
			var_exist(-1, flag, len, env);
	}
	return (1);
}
