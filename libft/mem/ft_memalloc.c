/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:04:32 by vbaudot           #+#    #+#             */
/*   Updated: 2017/11/10 10:12:28 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memalloc(size_t size)
{
	char	*fr;

	fr = malloc(sizeof(char) * size);
	if (fr == NULL)
		return (NULL);
	ft_memset(fr, 0, size);
	return (fr);
}
