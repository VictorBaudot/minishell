/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:31:14 by vbaudot           #+#    #+#             */
/*   Updated: 2017/11/12 11:06:15 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
				ret[i] = f(s[i]);
				i++;
			}
		}
	}
	return (ret);
}
