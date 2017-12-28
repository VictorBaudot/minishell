/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 09:43:26 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/28 14:42:44 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int ac, char **av)
{
	char *line;
	char **args;
	int status;

	status = 1;
	(void)ac;
	(void)av;
	while (status)
	{
		ft_putstr("$> ");
		line = read_line();
		args = ft_split_whitespaces(line);
		status = execute(args);
		free(line);
		free(args);
	}
}
