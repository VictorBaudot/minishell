/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 09:43:26 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/31 16:04:06 by vbaudot          ###   ########.fr       */
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
	if (ac == 1)
	{
		while (status)
		{
			ft_putstr(B_CY "☃ " B_BLU ">" B_R ">" B_Y ">" B_G " ");
			if (get_next_line(1, &line) != 1)
				exit(EXIT_SUCCESS);
			args = ft_split_whitespaces(line);
			ft_putstr(NC);
		//	(ft_strcmp(args[0], "ls") == 0) ? ft_putstr(NC) : ft_putstr(B_WH);
			status = execute(args, &env);
			free(line);
			free(args);
		}
	}
	else
		print_usage();
}
