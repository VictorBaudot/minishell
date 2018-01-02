/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 02:53:11 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/17 12:24:48 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "putf.h"

void	ft_x(va_list ap)
{
	int d;

	d = va_arg(ap, int);
	(d > 0) ? ft_putstr(ft_convert_base(d, 16, 0))
	: ft_putstr(ft_convert_base(4294967296 + d, 16, 0));
}

void	ft_u(va_list ap)
{
	int d;

	d = va_arg(ap, int);
	(d > 0) ? ft_putnbr(d) : ft_putnbr(4294967296 + d);
}

void	ft_ss(va_list ap)
{
	(void)ap;
	ft_putstr("NOT DONE YET");
}

void	ft_l(va_list ap)
{
	long	d;

	d = va_arg(ap, long);
	ft_putlnbr(d);
}

void	ft_ll(va_list ap)
{
	long long	d;

	d = va_arg(ap, long long);
	ft_putllnbr(d);
}
