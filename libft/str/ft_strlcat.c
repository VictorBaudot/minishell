/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:41:14 by vbaudot           #+#    #+#             */
/*   Updated: 2017/11/12 13:08:10 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dst[i])
		i++;
	if (size == 0)
		return (ft_strlen(src));
	if (src)
	{
		while (src[j] && (i + j) < (size - 1))
		{
			dst[i + j] = src[j];
			j++;
		}
	}
	dst[i + j] = '\0';
	if (size < i)
		return (ft_strlen(src) + size);
	else
		return (ft_strlen(src) + i);
}
