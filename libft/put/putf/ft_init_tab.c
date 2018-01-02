/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 20:04:30 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/17 12:23:43 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "putf.h"

static void	ft_init_tab_fc(t_ft **tab)
{
	t_ft *tmp;

	tmp = *tab;
	tmp[0].ft = ft_c;
	tmp[1].ft = ft_d;
	tmp[2].ft = ft_d;
	tmp[3].ft = ft_s;
	tmp[4].ft = ft_p;
	tmp[5].ft = ft_oo;
	tmp[6].ft = ft_x;
	tmp[7].ft = ft_u;
	tmp[8].ft = ft_ss;
	tmp[9].ft = ft_l;
	tmp[10].ft = ft_ll;
	tmp[11].ft = ft_uu;
	tmp[12].ft = ft_xx;
	tmp[13].ft = ft_cc;
	tmp[14].ft = NULL;
}

static void	ft_init_tab_char(t_ft **tab)
{
	t_ft *tmp;

	tmp = *tab;
	tmp[0].type = 'c';
	tmp[1].type = 'd';
	tmp[2].type = 'i';
	tmp[3].type = 's';
	tmp[4].type = 'p';
	tmp[5].type = 'o';
	tmp[6].type = 'x';
	tmp[7].type = 'u';
	tmp[8].type = 'S';
	tmp[9].type = 'l';
	tmp[10].type = 'L';
	tmp[11].type = 'U';
	tmp[12].type = 'X';
	tmp[13].type = 'C';
	tmp[14].type = 0;
}

void		ft_init_tab(t_ft **tab)
{
	ft_init_tab_fc(tab);
	ft_init_tab_char(tab);
}
