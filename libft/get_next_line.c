/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:23:01 by vbaudot           #+#    #+#             */
/*   Updated: 2018/01/01 18:02:24 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_read_and_fill(int fd, char **tab)
{
	char	buf[BUFF_SIZE + 1];
	char	*tmp;
	int		size;

	size = 3;
	ft_bzero(buf, BUFF_SIZE);
	while (!(ft_strchr(tab[fd], '\n')) && (size = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[size] = '\0';
		tmp = tab[fd];
		if (!(tab[fd] = ft_strjoin(tab[fd], buf)))
			return (-1);
		ft_strdel(&tmp);
	}
	return (size);
}

static int	end_of_file(char **tab, int fd, char **line)
{
	if (!(*line = ft_strdup(tab[fd])))
		return (-1);
	ft_strdel(tab + fd);
	if (ft_strlen(*line))
		return (1);
	else
	{
		ft_strdel(line);
		return (0);
	}
}

int			get_next_line(const int fd, char **line)
{
	static char	*tab[OPEN_MAX + 1];
	char		*tmp;
	int			ret;

	if (fd < 0 || line == NULL || fd > OPEN_MAX)
		return (-1);
	if (tab[fd] == NULL && (tab[fd] = ft_strnew(0)) == NULL)
		return (-1);
	if ((ret = ft_read_and_fill(fd, tab)) == -1)
		return (-1);
	if (ret == 0)
		return (end_of_file(tab, fd, line));
	if (!(*line = ft_strsub(tab[fd], 0, ft_strchr(tab[fd], '\n') - tab[fd])))
		return (-1);
	tmp = tab[fd];
	if (!(tab[fd] = ft_strdup(ft_strchr(tab[fd], '\n') + 1)))
		return (-1);
	ft_strdel(&tmp);
	return (1);
}
