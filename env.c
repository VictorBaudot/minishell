/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 16:26:47 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/31 13:26:19 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int print_env(char **env)
{
	int i;

	i = -1;
	while (env[++i])
		putf("%s\n", env[i]);
	return (1);
}

int	mini_env(char **args, char **env)
{
	if (!args[1])
		return (print_env(env));
	return (1);
}
