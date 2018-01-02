/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 12:41:18 by vbaudot           #+#    #+#             */
/*   Updated: 2018/01/02 15:56:47 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_symlink(const char *path)
{
	struct stat	sb;

	lstat(path, &sb);
	return (((sb.st_mode & S_IFMT) == S_IFLNK) ? 1 : 0);
}

static void	help_norm(char **env, char ***setenv)
{
	if (!(*setenv = (char **)malloc(sizeof(char *) * 4)))
		ft_error();
	(*setenv)[0] = ft_strdup("setenv");
	(*setenv)[1] = ft_strdup("OLDPWD");
	(*setenv)[2] = ft_strdup(ft_getenv(env, "PWD"));
	(*setenv)[3] = 0;
}

static int	modify_pwd(char **oldpwd, char ***env, char **args, int i)
{
	char	**setenv;
	char	*buf;

	buf = ft_memalloc(1024);
	help_norm(*env, &setenv);
	mini_setenv(setenv, env);
	free(setenv[1]);
	free(setenv[2]);
	setenv[1] = ft_strdup("PWD");
	if (is_symlink(args[1]))
		setenv[2] = ft_strdup(args[1]);
	else if (ft_strcmp(args[1], "-") == 0 && is_symlink(*oldpwd))
	{
		setenv[2] = ft_strdup(*oldpwd);
		free(*oldpwd);
	}
	else
		setenv[2] = ft_strdup(getcwd(buf, 1024));
	mini_setenv(setenv, env);
	while (setenv[++i])
		free(setenv[i]);
	free(setenv);
	free(buf);
	return (1);
}

int			mini_cd(char **args, char ***env)
{
	char	*oldpwd;

	if (!args[1])
		chdir(ft_getenv(*env, "HOME"));
	else
	{
		if (ft_strcmp(args[1], "-") == 0)
		{
			if (!args[2])
			{
				oldpwd = ft_strdup(ft_getenv(*env, "OLDPWD"));
				if (chdir(oldpwd) != 0)
					putf("minishell: dir not found / not the rights: %s\n",
					ft_getenv(*env, "OLDPWD"));
			}
			else
				ft_putendl("Usage: cd [-|<dir>].");
		}
		else if (chdir(args[1]) != 0)
			putf("minishell: dir not found / not the rights: %s\n", args[1]);
	}
	return (modify_pwd(&oldpwd, env, args, -1));
}
