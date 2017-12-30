/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 12:40:22 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/30 16:19:32 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int launch(char **args, char **env)
{
	pid_t pid;
	int status;
	char *path;

	pid = fork();
	path = ft_strdup(ft_path(env, args[0]));
	if (pid == 0)
	{
		if (execve(path, &args[0], env) == -1)
			perror("execve");
		free(path);
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		perror("mini");
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	free(path);
	return (1);
}
