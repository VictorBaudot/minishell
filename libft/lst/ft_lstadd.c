/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 10:17:47 by vbaudot           #+#    #+#             */
/*   Updated: 2017/11/12 10:28:04 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	t_list	*begin_list;

	begin_list = *alst;
	*alst = new;
	(*alst)->next = begin_list;
}
