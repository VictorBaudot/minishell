/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:33:57 by vbaudot           #+#    #+#             */
/*   Updated: 2017/11/12 11:18:26 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*ft_trim(size_t i, size_t j, size_t k, const char *s)
{
	char	*ret;

	ret = NULL;
	if (s)
	{
		if (s[0] == '\0')
			return ((char *)s);
		while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
			i++;
		j = ft_strlen(s) - 1;
		while (j > 0 && (s[j] == ' ' || s[j] == '\n' || s[j] == '\t'))
			j--;
		if (i > j && !(ret = (char *)malloc(sizeof(char))))
			return (NULL);
		else if (i <= j && !(ret = (char *)malloc(sizeof(char) * (2 + j - i))))
			return (NULL);
		while (i <= j)
		{
			ret[k] = s[i];
			k++;
			i++;
		}
		ret[k] = '\0';
	}
	return (ret);
}

char		*ft_strtrim(char const *s)
{
	return (ft_trim(0, 0, 0, s));
}
