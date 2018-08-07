/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshumba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 16:05:27 by dshumba           #+#    #+#             */
/*   Updated: 2018/05/29 16:05:30 by dshumba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *sub)
{
	int i;
	int pos;
	int len;

	i = 0;
	pos = 0;
	len = 0;
	while (sub[len] != '\0')
		len++;
	if (len == 0)
		return ((char *)str);
	while (str[i])
	{
		pos = 0;
		while (sub[pos] == str[i + pos])
		{
			if (pos == len - 1)
				return ((char *)str + i);
			pos++;
		}
		i++;
	}
	return (NULL);
}
