/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 20:16:53 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/17 11:19:17 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "putf.h"

int	ft_check(int i, char fmt, va_list ap, t_ft *tab)
{
	int	j;

	j = 0;
	while (tab[j].type)
	{
		if (tab[j].type == fmt)
		{
			tab[j].ft(ap);
			return (i + 1);
		}
		j++;
	}
	return (i);
}
