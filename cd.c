/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 12:41:18 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/31 18:39:04 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int mini_cd(char **args, char **env)
{
	char *buf;

	if (!args[1])
		chdir(ft_getenv(env, "HOME"));
	else
	{
		if (ft_strcmp(args[1], "-") == 0)
		{
			if (!args[2])
			{
				if (chdir(g_p_dir) != 0)
					putf("minishell: dir not found: %s\n", g_p_dir);
			}
			else
				ft_putendl("Usage: cd [-|<dir>].");
		}
		else if (chdir(args[1]) != 0)
			putf("minishell: dir not found: %s\n", args[1]);
	}
	buf = ft_memalloc(1024);
	free(g_p_dir);
	g_p_dir = ft_strdup(g_c_dir);
	free(g_c_dir);
	g_c_dir = ft_strdup(getcwd(buf, 1024));
	free(buf);
	return (1);
}
