/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 15:31:27 by vbaudot           #+#    #+#             */
/*   Updated: 2018/02/23 12:14:01 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*ft_getenv(t_list **head, char *elem)
{
	t_list	*curr;
	int		len;

	curr = *head;
	len = ft_strlen(elem);
	while (curr)
	{
		if (ft_strncmp(curr->content, elem, len) == 0)
		{
			return (&(curr->content)[len + 1]);
		}
		curr = curr->next;
	}
	return ("");
}

static int	check_two_points(char *tmp, int i, int *j)
{
	*j = ++i;
	while (tmp[i])
	{
		if (tmp[i] == ':')
			break ;
		i++;
	}
	return (i);
}

char		*ft_path(t_list **head, char *cmd)
{
	int		i;
	int		j;
	char	*tmp;
	char	*path;
	char	*final_path;

	tmp = ft_strdup(ft_getenv(head, "PATH"));
	i = -1;
	while (42)
	{
		i = check_two_points(tmp, i, &j);
		path = ft_strsub(tmp, j, (i - j));
		final_path = ft_str3join(path, "/", cmd);
		free(path);
		if (access(final_path, F_OK) == 0)
		{
			if (access(final_path, X_OK) != 0)
			{
				putf("minishell: not the rights: %s\n", cmd);
				free(tmp);
				free(final_path);
				exit(EXIT_FAILURE);
			}
			//putf("minishell: no such file or directory: %s\n", cmd);
			free(tmp);
			return (final_path);
		}
		free(final_path);
		if (!tmp[i])
			break ;
	}
	putf("minishell: command not found: %s\n", cmd);
	free(tmp);
	exit(0);
}
