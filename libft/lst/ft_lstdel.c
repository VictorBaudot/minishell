/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 09:54:31 by vbaudot           #+#    #+#             */
/*   Updated: 2017/11/12 10:16:03 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	if (alst && *alst)
	{
		while (*alst)
		{
			tmp = *alst;
			del((*alst)->content, (*alst)->content_size);
			*alst = (*alst)->next;
			free(tmp);
		}
		*alst = NULL;
	}
}
