/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 14:38:29 by vbaudot           #+#    #+#             */
/*   Updated: 2017/11/12 11:14:01 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_nbwords(char *str, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

static char	**ft_split(char **tab, char *str, char c, int *t)
{
	int j;
	int start;

	while (str[t[0]])
		if (str[t[0]] == c)
			t[0]++;
		else
		{
			start = t[0];
			while (str[t[0]] && str[t[0]] != c)
				t[0]++;
			tab[t[1]] = (char *)malloc(sizeof(char) * (1 + t[0] - start));
			j = 0;
			while (j < t[0] - start)
			{
				tab[t[1]][j] = str[start + j];
				j++;
			}
			tab[t[1]][j] = '\0';
			t[1]++;
		}
	tab[t[1]] = (char *)malloc(sizeof(char));
	tab[t[1]] = 0;
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	int		nbw;
	int		t[2];
	char	*str;
	char	**tab;

	t[0] = 0;
	t[1] = 0;
	str = (char *)s;
	if (s)
	{
		nbw = ft_nbwords(str, c);
		if (!(tab = (char **)malloc(sizeof(char *) * (nbw + 1))))
			return (NULL);
		return (ft_split(tab, str, c, t));
	}
	else
		return (NULL);
}
