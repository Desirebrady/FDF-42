/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshumba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 13:18:03 by dshumba           #+#    #+#             */
/*   Updated: 2018/05/30 10:33:19 by dshumba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		exceeds_n(int n)
{
	if (n == -1)
		return (0);
	return (-1);
}

int				ft_atoi(const char *str)
{
	int			i;
	int			lim;
	int			n;

	n = 1;
	while ((*str >= '\t' && *str <= '\r') || *str == 32 || *str == '0')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			n = -1;
		str++;
	}
	lim = 0;
	i = 0;
	while (*str >= '0' && *str <= '9' && *str)
	{
		i = (i * 10) + (*str++ - '0');
		if (lim >= 19)
			return (exceeds_n(n));
		lim++;
	}
	return (i * n);
}
