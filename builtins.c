/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 12:38:15 by vbaudot           #+#    #+#             */
/*   Updated: 2018/02/23 11:59:17 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			mini_exit(char **args)
{
	ft_putendl("exit");
	if (args[1])
	{
		ft_putendl("exit: Too many arguments");
		return (1);
	}
	return (0);
}
