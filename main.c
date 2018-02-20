/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 09:43:26 by vbaudot           #+#    #+#             */
/*   Updated: 2018/02/20 11:51:42 by vbaudot          ###   ########.fr       */
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
	char	**envc;
	char	**args;
	int		status;
	int		x;

	status = 1;
	(void)ac;
	(void)av;
	signal(SIGINT, handler);
	x = 0;
	while (env[x])
		x++;
	if (!(envc = (char **)malloc(sizeof(char *) * (x + 1))))
		return (1);
	envc[x] = 0;
	x = -1;
	while (env[++x])
		envc[x] = ft_strdup(env[x]);
	if (ac == 1)
	{
		while (status)
		{
			ft_putstr(B_CY "☃ " B_BLU ">" B_R ">" B_Y ">" B_G " ");
			if (get_next_line(1, &line) != 1)
				handler(0);
			args = ft_split_whitespaces(line);
			free(line);
			ft_putstr(NC);
			status = execute(args, &envc);
			x = -1;
			while (args[++x])
				free(args[x]);
			free(args);
		}
	}
	else
		print_usage();
	x = -1;
	while (envc[++x])
		free(envc[x]);
	free(envc);
	return (0);
}
