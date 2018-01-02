/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 10:31:54 by vbaudot           #+#    #+#             */
/*   Updated: 2017/11/12 10:47:58 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlst;
	t_list	*tmp;
	t_list	*beginlst;

	if (!lst || !f)
		return (NULL);
	tmp = f(lst);
	if (!(newlst = ft_lstnew(tmp->content, tmp->content_size)))
		return (NULL);
	beginlst = newlst;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		if (!(newlst->next = ft_lstnew(tmp->content, tmp->content_size)))
			return (NULL);
		newlst = newlst->next;
		lst = lst->next;
	}
	return (beginlst);
}
