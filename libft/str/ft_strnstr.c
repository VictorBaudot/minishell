/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:04:39 by vbaudot           #+#    #+#             */
/*   Updated: 2017/11/13 09:07:56 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		j;
	int		l;
	char	*c;

	i = 0;
	while (((char *)haystack)[i] && i < len)
	{
		j = 0;
		l = i;
		c = &((char *)haystack)[i];
		while ((((char *)haystack)[i] == needle[j] ||
					needle[0] == '\0') && i < len)
		{
			if (needle[j + 1] == '\0' || needle[0] == '\0')
				return (c);
			i++;
			j++;
		}
		if (j == 0)
			i++;
		else
			i = l + 1;
	}
	return (NULL);
}
