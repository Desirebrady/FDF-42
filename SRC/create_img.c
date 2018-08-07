/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshumba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 13:59:40 by dshumba           #+#    #+#             */
/*   Updated: 2018/07/13 13:59:41 by dshumba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

t_img	*create_img(t_mlx *obj)
{
	t_img	*new;

	new = (t_img*)malloc(sizeof(t_img));
	new->bpp = 0;
	new->size_line = 0;
	new->end = 0;
	new->img = mlx_new_image(obj->mlx, SIZE_X, SIZE_Y);
	new->line = CREATE_IMAGE(new->img, &new->bpp, &new->size_line, &new->end);
	return (new);
}
