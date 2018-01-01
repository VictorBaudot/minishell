/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 15:31:27 by vbaudot           #+#    #+#             */
/*   Updated: 2018/01/01 16:12:47 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_getenv(char **env, char *elem)
{
	int i;
	int j;
	int len;

	i = -1;
	len = ft_strlen(elem);
	while (env[++i])
	{
		j = -1;
		while (elem[++j])
		{
			if (env[i][j] != elem[j])
				break;
		}
		if (j == len)
			return (&env[i][j + 1]);
	}
	return ("");
}

char	*ft_path(char **env, char *cmd)
{
	int i;
	int j;
	char *tmp;
	char *path;
	char *final_path;

	tmp = ft_strdup(ft_getenv(env, "PATH"));
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
		path = ft_strsub(tmp, j, (i - j));
		final_path = ft_str3join(ft_strsub(tmp, j, (i - j)), "/", cmd);
		free(path);
		if (access(final_path, F_OK) == 0)
		{
			free(tmp);
			return (final_path);
		}
		free(final_path);
		if (!tmp[i])
			break ;
	}
	free(tmp);
	return ("");
}
