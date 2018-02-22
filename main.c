/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 09:43:26 by vbaudot           #+#    #+#             */
/*   Updated: 2018/02/22 15:41:39 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handler(int sig)
{
	(void)sig;
	ft_putendl(NC "\nexit");
	exit(EXIT_SUCCESS);
}

t_list		*create_env_list(char **env)
{
	t_list	*start;
	t_list	**begin_list;
	t_list	*new;
	int		x;

	x = 0;
	start = ft_lstnew(env[x], ft_strlen(env[x]));
	begin_list = &start;
	while (env[++x])
	{
		new = ft_lstnew(env[x], ft_strlen(env[x]));
		ft_lstappend(&start, new);
		start = start->next;

	}
	ft_lstprint(begin_list);
	return (start);
}

int			main(int ac, char **av, char **env)
{
	char	*line;
	char	**envc;
	char	**args;
	int		status;
	t_list	*start;
	int		x;

	status = 1;
	(void)ac;
	(void)av;
	signal(SIGINT, handler);
	x = 0;
	start = create_env_list(env);
	while (env[x])
		x++;
	if (!(envc = (char **)malloc(sizeof(char *) * (x + 1))))
		return (1);
	envc[x] = 0;
	x = -1;
	while (env[++x])
		envc[x] = ft_strdup(env[x]);
	// Pourquoi envc n apparait pas dans les leaks pendant l exececution du prog?
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
	exit (0);
}
