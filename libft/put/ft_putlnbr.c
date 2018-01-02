/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 09:55:33 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/17 10:54:29 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putlnbr(long n)
{
	unsigned long long	i;
	unsigned long long	p;

	i = 1;
	if (n == -9223372036854775807 - 1)
		ft_putstr("-9223372036854775808");
	else
	{
		if (n < 0)
		{
			ft_putchar('-');
			n = -n;
		}
		p = n;
		while (i <= p)
			i *= 10;
		while (i > 10)
		{
			i /= 10;
			ft_putchar((n / i) + '0');
			n = n % i;
		}
		ft_putchar((n % 10) + '0');
	}
}
