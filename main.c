/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 09:43:26 by vbaudot           #+#    #+#             */
/*   Updated: 2018/01/02 09:36:58 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handler(int sig)
{
	(void)sig;
	ft_putendl(NC "\nexit");
	exit(EXIT_SUCCESS);
}

int			main(int ac, char **av, char **env)
{
	char	*line;
	char	**args;
	int		status;

	status = 1;
	(void)ac;
	(void)av;
	signal(SIGINT, handler);
	if (ac == 1)
	{
		while (status)
		{
			ft_putstr(B_CY "☃ " B_BLU ">" B_R ">" B_Y ">" B_G " ");
			if (get_next_line(1, &line) != 1)
				handler(0);
			args = ft_split_whitespaces(line);
			ft_putstr(NC);
			status = execute(args, &env);
			free(line);
			free(args);
		}
	}
	else
		print_usage();
	return (0);
}
