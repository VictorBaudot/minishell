/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 12:03:40 by vbaudot           #+#    #+#             */
/*   Updated: 2018/02/23 11:49:56 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstprint(t_list **head)
{
	t_list	*curr;

	curr = *head;
	while (curr)
	{
		if (curr->content)
			ft_putendl(curr->content);
		curr = curr->next;
	}
}
