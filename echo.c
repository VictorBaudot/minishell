/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 12:38:38 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/30 10:17:21 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	mini_echo(char **args, char **env)
{
	int i;

	i = 0;
	(void)env;
	while (args[++i])
	{
		ft_putstr(args[i]);
		if (args[i + 1])
			ft_putchar(' ');
	}
	ft_putendl("");
	return (1);
}
