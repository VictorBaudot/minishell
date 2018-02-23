/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 11:29:15 by vbaudot           #+#    #+#             */
/*   Updated: 2018/02/23 13:40:41 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_lsterase(t_list **head)
{
	t_list *tmp;

	while (*head)
	{
		tmp = *head;
		free((*head)->content);
		*head = (*head)->next;
		free(tmp);
	}
	*head = NULL;
}

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
		tmp=tmp2;

	}
	return (head);
}

int			list_len(t_list **head)
{
	t_list	*curr;
	int		len;

	curr = *head;
	len = 1;
	while (curr)
	{
		len++;
		curr = curr->next;
	}
	return (len);
}

char		**create_env_from_list(t_list **head)
{
	t_list	*curr;
	char	**env;
	int		i;

	i = 0;
	curr = *head;
	env = (char **)malloc(sizeof(char *) * list_len(head));
	while (curr)
	{
		env[i++] = ft_strdup(curr->content);
		curr = curr->next;
	}
	env[i] = NULL;
	return (env);
}

void		ft_lstdelthis(t_list **head, char *str)
{
	t_list *prev;
	t_list *curr;
	int		len;

	curr = *head;
	len = ft_strlen(str);
	while (curr)
	{
		if (ft_strncmp(curr->content, str, len) == 0 && ((char *)curr->content)[len] == '=')
		{
			free(curr->content);
			if (curr->next)
			{
				prev->next = curr->next;
				free(curr);
				prev = prev->next;
				curr = prev->next;
			}
			else
			{
				free(curr);
				prev->next = NULL;
				curr = prev;
			}
		}
		else {
			prev = curr;
			curr = curr->next;
		}
	}
}
