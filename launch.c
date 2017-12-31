/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 12:40:22 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/31 18:06:09 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int launch(char **args, char **env)
{
	pid_t pid;
	int status;
	char *path;

	pid = fork();
	if (args[0][0] == '.')
		path = ft_strdup(args[0]);
	else
		path = ft_strdup(ft_path(env, args[0]));
	if (pid == 0)
	{
		if (execve(path, &args[0], env) == -1)
			putf("minishell: command not found: %s\n", args[0]);
		free(path);
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		ft_putendl("minishell: fork error\n");
	else
	{
		waitpid(pid, &status, WUNTRACED);
		while (!WIFEXITED(status) && !WIFSIGNALED(status))
			waitpid(pid, &status, WUNTRACED);
	}
	free(path);
	return (1);
}
