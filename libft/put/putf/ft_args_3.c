/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 02:53:09 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/17 11:18:24 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "putf.h"

void	ft_uu(va_list ap)
{
	size_t d;

	d = va_arg(ap, size_t);
	(d > 0) ? ft_putnbr(d) : ft_putnbr(4294967296 + d);
}

void	ft_xx(va_list ap)
{
	int d;

	d = va_arg(ap, int);
	(d > 0) ? ft_putstr(ft_convert_base(d, 16, 1))
	: ft_putstr(ft_convert_base(4294967296 + d, 16, 1));
}

void	ft_cc(va_list ap)
{
	(void)ap;
	ft_putstr("NOT DONE YET");
}
