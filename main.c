/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 09:43:26 by vbaudot           #+#    #+#             */
/*   Updated: 2018/02/24 09:52:19 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handler(int sig)
{
	(void)sig;
	ft_putendl(NC "\nexit");
	exit(EXIT_SUCCESS);
}

void		main_loop(t_list **head, int status)
{
	char	*line;
	char	**args;
	int		x;

	signal(SIGINT, handler);
	while (status)
	{
		ft_putstr(B_CY "☃ " B_BLU ">" B_R ">" B_Y ">" B_G " ");
		if (get_next_line(1, &line) != 1)
			handler(0);
		args = ft_split_whitespaces(line);
		free(line);
		ft_putstr(NC);
		status = execute(args, head);
		x = -1;
		while (args[++x])
			free(args[x]);
		free(args);
	}
}

int			main(int ac, char **av, char **env)
{
	t_list	*head;

	head = create_list_from_env(env);
	if (ac == 1 && av[0] != NULL)
		main_loop(&head, 1);
	else
		print_usage();
	ft_lsterase(&head);
	exit(EXIT_SUCCESS);
}
