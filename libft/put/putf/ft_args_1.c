/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 20:28:34 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/17 11:18:33 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "putf.h"

void	ft_c(va_list ap)
{
	char c;

	c = va_arg(ap, int);
	ft_putchar(c);
}

void	ft_d(va_list ap)
{
	int d;

	d = va_arg(ap, int);
	ft_putnbr(d);
}

void	ft_s(va_list ap)
{
	char *s;

	s = va_arg(ap, char *);
	ft_putstr(s);
}

void	ft_p(va_list ap)
{
	size_t d;

	d = va_arg(ap, size_t);
	ft_putstr("0x");
	(d > 0) ? ft_putstr(ft_convert_base(d, 16, 0))
	: ft_putstr(ft_convert_base(4294967296 + d, 16, 0));
}

void	ft_oo(va_list ap)
{
	int d;

	d = va_arg(ap, int);
	(d > 0) ? ft_putstr(ft_convert_base(d, 8, 0))
	: ft_putstr(ft_convert_base(4294967296 + d, 8, 0));
}
