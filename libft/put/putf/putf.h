/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 02:24:54 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/19 16:58:57 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUTF_H
# define PUTF_H

# include <fcntl.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../../libft.h"
# include <stdarg.h>

typedef	struct	s_ft
{
	char		type;
	void		(*ft)(va_list);
}				t_ft;

void			ft_c(va_list ap);
void			ft_d(va_list ap);
void			ft_s(va_list ap);
void			ft_p(va_list ap);
void			ft_oo(va_list ap);
void			ft_x(va_list ap);
void			ft_u(va_list ap);
void			ft_ss(va_list ap);
void			ft_l(va_list ap);
void			ft_ll(va_list ap);
void			ft_uu(va_list ap);
void			ft_xx(va_list ap);
void			ft_cc(va_list ap);

void			ft_error(void);
char			*ft_convert_base(unsigned long long jack, int base, int cas);
void			ft_init_tab(t_ft **tab);
int				ft_check(int i, char fmt, va_list ap, t_ft	*tab);
int				putf(const char *format, ...);

#endif
