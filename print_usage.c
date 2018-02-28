/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_usage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 14:04:58 by vbaudot           #+#    #+#             */
/*   Updated: 2018/02/28 09:55:11 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_error(void)
{
	ft_putstr("error.\n");
	exit(EXIT_FAILURE);
}

int		ft_problem_dir(char *arg)
{
	putf("minishell: dir not found / not the rights: %s\n", arg);
	return (1);
}

void	print_usage(void)
{
	ft_putstr("usage: ./minishell\n");
	exit(EXIT_FAILURE);
}
