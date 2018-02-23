/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 12:10:18 by vbaudot           #+#    #+#             */
/*   Updated: 2018/02/23 13:06:15 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstappend(t_list **head, t_list *new)
{
	t_list	*lst;

	lst = *head;
	if (new)
	{
		if (!lst)
			lst = new;
		else
		{
			while (lst && lst->next)
				lst = lst->next;
			lst->next = new;
		}
	}
}
