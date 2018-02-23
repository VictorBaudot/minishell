/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 09:43:26 by vbaudot           #+#    #+#             */
/*   Updated: 2018/02/23 16:10:06 by vbaudot          ###   ########.fr       */
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
	t_list	*head;
	int		x;

	status = 1;
	(void)ac;
	(void)av;
	signal(SIGINT, handler);
	head = create_list_from_env(env);
	//ft_lstdelthis(&head, "PAGER");
	//ft_lstprint(&head);
	//putf("->%s<-\n", ft_getenv(&head, "LESS"));
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
			status = execute(args, &head);
			x = -1;
			while (args[++x])
				free(args[x]);
			free(args);
		}
	}
	else
		print_usage();
	ft_lsterase(&head);
	exit (0);
}
