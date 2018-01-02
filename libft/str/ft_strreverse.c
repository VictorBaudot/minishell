/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:10:10 by vbaudot           #+#    #+#             */
/*   Updated: 2017/11/13 09:40:18 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strreverse(char *s)
{
	size_t	i;
	size_t	len;
	char	*r;

	i = 0;
	r = NULL;
	if (s)
	{
		len = ft_strlen(s);
		if (!(r = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		if (r)
		{
			while (i < len)
			{
				r[i] = s[len - i - 1];
				i++;
			}
			r[i] = '\0';
		}
	}
	return (r);
}
