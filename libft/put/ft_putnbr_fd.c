/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:55:16 by vbaudot           #+#    #+#             */
/*   Updated: 2017/11/11 09:46:20 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	i;

	i = 1;
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n = -n;
		}
		while (i <= n)
			i *= 10;
		while (i > 10)
		{
			i /= 10;
			ft_putchar_fd((n / i) + '0', fd);
			n = n % i;
		}
		ft_putchar_fd((n % 10) + '0', fd);
	}
}
