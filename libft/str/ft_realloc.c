/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 10:09:26 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/28 10:10:21 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_realloc(char **str, int bufsize)
{
	char	*copy;

	if (!(copy = malloc(sizeof(char) * (bufsize + ft_strlen(*str)))))
	{
		ft_putstr("Reallocation error.\n");
		exit(EXIT_FAILURE);
	}
	copy = ft_strcpy(copy, *str);
	free(*str);
	return (copy);
}
