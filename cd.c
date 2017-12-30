/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 12:41:18 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/30 10:17:21 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int mini_cd(char **args, char **env)
{
	(void)env;
	if (args[1] == NULL)
		fprintf(stderr, "mini: expected argument to \"cd\"\n");
	else
		if (chdir(args[1]) != 0)
		perror("mini");
	return (1);
}
