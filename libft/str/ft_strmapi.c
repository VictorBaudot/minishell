/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:32:02 by vbaudot           #+#    #+#             */
/*   Updated: 2017/11/10 10:48:56 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		len;
	char	*ret;

	i = 0;
	ret = NULL;
	if (s)
	{
		len = ft_strlen(s);
		ret = ft_strnew(len);
		if (ret)
		{
			while (i < len)
			{
				ret[i] = f(i, s[i]);
				i++;
			}
		}
	}
	return (ret);
}
