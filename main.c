/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 09:43:26 by vbaudot           #+#    #+#             */
/*   Updated: 2018/01/01 12:52:32 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int ac, char **av, char **env)
{
	char *line;
	char **args;
	char *buf;
	int status;

	status = 1;
	buf = ft_memalloc(1024);
	g_c_dir = ft_strdup(getcwd(buf, 1024));
	g_p_dir = ft_strdup(getcwd(buf, 1024));
	free(buf);
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
			status = execute(args, &env);
			free(line);
			free(args);
		}
	}
	else
		print_usage();
	ft_putstr(NC);
	free(g_c_dir);
	free(g_p_dir);
	return (0);
}
