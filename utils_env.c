/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 12:53:19 by vbaudot           #+#    #+#             */
/*   Updated: 2018/02/23 12:47:44 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	too_many_args(char *cmd)
{
	putf("minishell: %s: too many arguments\n", cmd);
	return (1);
}
/*
int	check_env(char **args, char ***env, int *i)
{
	int		j;
	int		flag;

	flag = -3;
	while (flag == -3 && (*env)[*i])
	{
		j = -1;
		while (args[1][++j])
		{
			if (args[1][j] != (*env)[*i][j])
				break ;
			if ((*env)[*i][j + 1] == '=')
				flag = *i;
		}
		(*i)++;
	}
	return (flag);
}
*/
