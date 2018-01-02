/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 23:05:43 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/17 11:10:48 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "putf.h"

static void	ft_case(char *str, unsigned long long jack,
			unsigned long long base, unsigned long long i)
{
	if (i >= base)
	{
		if ((jack / i) < 10)
			*str = jack / i + '0';
		else
			*str = jack / i - 10 + 'a';
		ft_case((str + 1), (jack % i), base, (i / base));
		return ;
	}
	if (jack / i < 10)
		*str = jack / i + '0';
	else
		*str = jack / i - 10 + 'a';
}

static void	ft_c_maj(char *str, unsigned long long jack,
			unsigned long long base, unsigned long long i)
{
	if (i >= base)
	{
		if ((jack / i) < 10)
			*str = jack / i + '0';
		else
			*str = jack / i - 10 + 'A';
		ft_c_maj((str + 1), (jack % i), base, (i / base));
		return ;
	}
	if (jack / i < 10)
		*str = jack / i + '0';
	else
		*str = jack / i - 10 + 'A';
}

char		*ft_convert_base(unsigned long long jack, int base, int cas)
{
	unsigned long long	i;
	unsigned long long	test;
	char				*str;
	unsigned long long	count;
	unsigned int		j;

	j = 0;
	i = 1;
	count = 0;
	test = jack;
	while ((test = test / base))
		count++;
	count++;
	while (j++ < (count - 1))
		i = i * base;
	if (base < 2 || !(str = (char*)malloc(sizeof(char) * (count + 1))))
		return (NULL);
	str[count] = '\0';
	if (jack == 0)
		str[0] = '0';
	else
		(cas == 0) ? ft_case(str, jack, base, i) : ft_c_maj(str, jack, base, i);
	return (str);
}
