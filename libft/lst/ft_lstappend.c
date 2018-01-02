/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 12:10:18 by vbaudot           #+#    #+#             */
/*   Updated: 2017/11/15 10:38:51 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstappend(t_list **lst, t_list *new)
{
	if (new)
	{
		if (!(*lst))
			*lst = new;
		else
		{
			while (*lst && (*lst)->next)
				*lst = (*lst)->next;
			(*lst)->next = new;
		}
	}
}
