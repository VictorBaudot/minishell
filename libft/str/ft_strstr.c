/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:21:04 by vbaudot           #+#    #+#             */
/*   Updated: 2017/11/11 13:11:56 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	int		k;
	char	*c;
	char	*hs;

	i = 0;
	hs = (char *)haystack;
	if (hs[0] == '\0' && needle[0] == '\0')
		return (&hs[0]);
	while (hs[i])
	{
		j = 0;
		k = i;
		c = &hs[i];
		while (hs[k] == needle[j] || needle[0] == '\0')
		{
			if (needle[j + 1] == '\0' || needle[0] == '\0')
				return (c);
			k++;
			j++;
		}
		i++;
	}
	return (NULL);
}
