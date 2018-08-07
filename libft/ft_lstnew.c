/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshumba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 13:21:15 by dshumba           #+#    #+#             */
/*   Updated: 2018/05/30 09:22:06 by dshumba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*lnew;

	if (!(lnew = (t_list *)malloc(sizeof(*lnew))))
		return (NULL);
	if (!content)
	{
		lnew->content = NULL;
		lnew->content_size = 0;
	}
	else
	{
		if (!(lnew->content = malloc(content_size)))
			return (NULL);
		ft_memcpy(lnew->content, content, content_size);
		lnew->content_size = content_size;
	}
	lnew->next = NULL;
	return (lnew);
}
