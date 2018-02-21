/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 12:40:22 by vbaudot           #+#    #+#             */
/*   Updated: 2018/02/21 15:23:27 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_slash(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == '/')
			return (1);
	return (0);
}

int			launch(char **args, char ***env)
{
	pid_t	pid;
	int		status;
	char	*path;
	int		x;
	int		flag;
	char	**envc;

	ft_putstr("START LAUNCH\n");
	pid = fork();
	if (pid == 0)
	{
		flag = 3;
		if (ft_strcmp(args[0], "setenv") == 0)
			flag = mini_setenv(args, env);
		else if (ft_strcmp(args[0], "unsetenv") == 0)
			flag = mini_unsetenv(args, env);
		else if (ft_strcmp(args[0], "cd") == 0)
			flag = mini_cd(args, env);
		else if (ft_strcmp(args[0], "env") == 0)
		{
			x = 0;
			while ((*env)[x])
				x++;
			if (!(envc = (char **)malloc(sizeof(char *) * (x + 1))))
				return (0);
			envc[x] = 0;
			x = -1;
			while ((*env)[++x])
				envc[x] = ft_strdup((*env)[x]);
			flag = mini_env(args, envc);
			ft_putstr("Fin.\n");
		}
		else {
			path = (check_slash(args[0]) == 1) ? ft_strdup(args[0]) :
			ft_strdup(ft_path(*env, args[0]));
			execve(path, &args[0], *env);
			free(path);
		}
		if (flag != 3)
			exit(0);
		return (0);
	}
	else if (pid < 0)
		ft_putendl("minishell: fork error\n");
	else
	{
		waitpid(pid, &status, WUNTRACED);
		while (!WIFEXITED(status) && !WIFSIGNALED(status))
			waitpid(pid, &status, WUNTRACED);
	}
	return (1);
}
