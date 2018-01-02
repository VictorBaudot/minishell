/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 13:27:30 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/10 13:37:10 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putfnbr(long double nbr, int power)
{
	unsigned long x;

	x = 0;
	if (nbr == 1)
		ft_putchar('1');
	while (nbr > 1)
	{
		nbr /= 10;
		x++;
	}
	if (x == 0 && nbr != 1)
		ft_putchar('0');
	else
		while (x--)
		{
			nbr = (nbr - (int)(nbr + 0.1)) * 10;
			ft_putchar((int)(nbr + 0.1) + '0');
		}
	ft_putchar('.');
	while (nbr > pow(0.1, power))
	{
		nbr = (nbr - (int)(nbr + 0.1)) * 10;
		ft_putchar((int)(nbr + 0.1) + '0');
	}
}
