/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 11:29:15 by vbaudot           #+#    #+#             */
/*   Updated: 2018/02/24 09:23:31 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list		*create_list_from_env(char **env)
{
	t_list	*tmp;
	t_list	*head;
	t_list	*tmp2;
	int		x;

	x = 0;
	tmp = ft_lstnew(env[x], ft_strlen(env[x]));
	head = tmp;
	while (env[++x])
	{
		tmp2 = ft_lstnew(env[x], ft_strlen(env[x]));
		tmp->next = tmp2;
		tmp = tmp2;
	}
	return (head);
}

int			list_len(t_list **head)
{
	t_list	*curr;
	int		len;

	len = 1;
	if (*head != NULL)
	{
		curr = *head;
		while (curr)
		{
			len++;
			curr = curr->next;
		}
	}
	return (len);
}

char		**create_env_from_list(t_list **head)
{
	t_list	*curr;
	char	**env;
	int		i;

	i = 0;
	env = (char **)malloc(sizeof(char *) * list_len(head));
	if (*head != NULL)
	{
		curr = *head;
		while (curr)
		{
			env[i++] = ft_strdup(curr->content);
			curr = curr->next;
		}
	}
	env[i] = NULL;
	return (env);
}
