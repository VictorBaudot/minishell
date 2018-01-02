/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:54:27 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/14 11:15:41 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int			ft_nblen(int nb)
{
	if (!nb)
		return (0);
	return (ft_nblen(nb / 10) + 1);
}

char				*ft_itoa(int nb)
{
	char	*res;
	int		len;
	int		is_neg;
	long	tmp;

	tmp = nb;
	len = (tmp ? ft_nblen(tmp) : 1);
	is_neg = tmp < 0 ? 1 : 0;
	if (!(res = (char*)malloc(sizeof(char) * (len + is_neg + 1))))
		exit(EXIT_FAILURE);
	res[len + is_neg] = '\0';
	if (is_neg)
	{
		res[0] = '-';
		tmp *= -1;
	}
	len += is_neg;
	while (len > 0 + is_neg)
	{
		res[--len] = (tmp % 10) + '0';
		tmp /= 10;
	}
	return (res);
}
