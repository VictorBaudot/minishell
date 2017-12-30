/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 09:43:26 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/30 09:48:25 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int ac, char **av, char **env)
{
	char *line;
	char **args;
	int status;

	status = 1;
	(void)ac;
	(void)av;
	while (status)
	{
		ft_putstr(">>> ");
		if (get_next_line(1, &line) != 1)
			exit(EXIT_SUCCESS);
		args = ft_split_whitespaces(line);
		status = execute(args, env);
		free(line);
		free(args);
	}
}
