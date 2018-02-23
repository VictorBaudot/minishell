/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 13:25:54 by vbaudot           #+#    #+#             */
/*   Updated: 2018/02/23 12:47:12 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
int			var_dont_exist(int i, char **args, t_list **head)
{
	char	**tmp;

	if (!(tmp = (char **)malloc(sizeof(char *) * (i + 1))))
		return (1);
	tmp[i] = 0;
	i = -1;
	while ((*env)[++i]){
		ft_putstr((*env)[i]);
		ft_putstr("\n");
		tmp[i] = ft_strdup((*env)[i]);
	}
	if (!(*env = (char **)malloc(sizeof(char *) * (i + 2))))
		return (1);
	(*env)[i + 1] = 0;
	if (args[2])
		(*env)[i] = ft_str3join(args[1], "=", args[2]);
	else
		(*env)[i] = ft_str3join(args[1], "=", "");
	i = -1;
	while (tmp[++i]){
		(*env)[i] = ft_strdup(tmp[i]);
	}
	i = -1;
	while (tmp[++i])
		free(tmp[i]);
	free(tmp);
	return (1);
}*/

int			mini_setenv(char **args, t_list **head)
{
	int		i;
//	int		flag;

	i = -1;
	if (!args[1])
		ft_lstprint(head);
	else
	{
		while (args[1][++i])
			if (args[1][i] == '=')
			{
				ft_putendl("minishell: setenv: variable name is not valid.");
				return (1);
			}
		if (args[3])
			return (too_many_args("setenv"));
		i = 0;/*
		flag = check_env(args, env, &i);
		//putf("flag=%d i-1=%d\n", flag, i - 1);
		if (flag == i - 1 && args[2])
			(*env)[i - 1] = ft_str3join(args[1], "=", args[2]);
		else if (flag == i - 1)
			(*env)[i - 1] = ft_str3join(args[1], "=", "");
		else
			return (var_dont_exist(i, args, env));*/
	}
	return (1);
}

int			mini_unsetenv(char **args, t_list **head)
{
	int		j;

	if (!args[1])
		ft_lstprint(head);
	j = 0;
	while (args[++j])
	{
		if (ft_strcmp(args[j], "*") == 0)
		{
			ft_lsterase(head);
			return (1);
		}
		ft_lstdelthis(head, args[j]);
	}
	return (1);
}
