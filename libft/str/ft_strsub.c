/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:56:43 by vbaudot           #+#    #+#             */
/*   Updated: 2017/11/12 11:07:44 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	s_start;
	size_t	i;

	ret = NULL;
	i = 0;
	s_start = (size_t)start;
	if (s && len + s_start <= ft_strlen(s))
	{
		ret = ft_strnew(len);
		if (ret)
		{
			while (i < len)
			{
				ret[i] = s[s_start + i];
				i++;
			}
			ret[len] = '\0';
		}
	}
	return (ret);
}
