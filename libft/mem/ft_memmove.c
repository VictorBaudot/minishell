/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 09:20:52 by vbaudot           #+#    #+#             */
/*   Updated: 2017/11/13 11:18:44 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = -1;
	if ((char *)src < (char *)dst)
		while ((int)(--len) >= 0)
			*((char *)dst + len) = *((char *)src + len);
	else
		while (++i < len)
			*((char *)dst + i) = *((char *)src + i);
	return ((char *)dst);
}
