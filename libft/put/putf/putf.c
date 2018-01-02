/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 02:23:55 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/17 11:09:54 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "putf.h"

/*
** c - char
** s - string
** d - int
** l = ld - long
** L = lld - long long
** p - pointeur
** o - octal non signe
** u - decimal non signe
** U = zu - size_t non signe
** x - hexadecimal non signe [abcdef]
** X - hexadecimal non signe [ABCDEF]
*/

int	putf(const char *fmt, ...)
{
	t_ft	*tab;
	va_list ap;
	int		i;

	va_start(ap, fmt);
	i = -1;
	if (!(tab = (t_ft*)malloc(15 * sizeof(t_ft))))
		exit(EXIT_FAILURE);
	ft_init_tab(&tab);
	while (fmt[++i])
	{
		if (fmt[i] == '%' && fmt[i - 1] != '\\' && fmt[i + 1] != '%')
			i = ft_check(i, fmt[i + 1], ap, tab);
		else
		{
			if (fmt[i] == '%' && fmt[i - 1] != '\\' && fmt[i + 1] == '%')
				i = i + 1;
			ft_putchar(fmt[i]);
		}
	}
	free(tab);
	va_end(ap);
	return (0);
}
