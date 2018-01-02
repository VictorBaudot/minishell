/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 13:25:54 by vbaudot           #+#    #+#             */
/*   Updated: 2018/01/02 10:34:21 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	mini_setenv(char **args, char ***env)
{
	int i;
	int j;
	int flag;
	char **tmp;

	i = 0;
	if (!args[1])
		return (print_env(*env));
	if (!args[2])
		args[2] = "";
	if (args[3])
	{
		ft_putendl("minishell: setenv: too many arguments");
		return (1);
	}
	flag = 0;
	while (flag == 0 && (*env)[i])
	{
		j = -1;
		while (args[1][++j])
		{
			if (args[1][j] != (*env)[i][j])
				break ;
			if ((*env)[i][j + 1] == '=')
				flag = 1;
		}
		i++;
	}
	if (flag == 1)
		(*env)[i - 1] = ft_str3join(args[1], "=", args[2]);
	else
	{
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
	}
	return (1);
}

int	mini_unsetenv(char **args, char ***env)
{
	int i;
	int j;
	int len;
	int flag;
	char **tmp;

	i = 0;
	if (!args[1])
		return (print_env(*env));
	if (ft_strcmp(args[1], "*") == 0)
	{
		if (!(*env = (char **)malloc(sizeof(char *))))
			return (1);
		(*env)[0] = 0;
		print_env(*env);
		return (1);
	}
	if (args[2])
	{
		ft_putendl("minishell: unsetenv: too many arguments");
		return (1);
	}
	flag = -1;
	while (flag == -1 && (*env)[i])
	{
		j = -1;
		while (args[1][++j])
		{
			if (args[1][j] != (*env)[i][j])
				break ;
			if ((*env)[i][j + 1] == '=')
				flag = i;
		}
		i++;
	}
	len = -1;
	while ((*env)[++len]){}
	if (flag == i - 1 && i != 0)
	{
		if (!(tmp = (char **)malloc(sizeof(char *) * (len))))
			return (1);
		tmp[len - 1] = 0;
		i = -1;
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
		{
			(*env)[i] = ft_strdup(tmp[i]);
		}
		i = -1;
		while (tmp[++i])
			free(tmp[i]);
		free(tmp);
	}
	return (1);
}
