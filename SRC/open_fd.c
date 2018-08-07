/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshumba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 14:02:01 by dshumba           #+#    #+#             */
/*   Updated: 2018/07/13 14:02:02 by dshumba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/head.h"

int		open_fd(char *argv)
{
	int		fd;

	if ((fd = open(argv, O_RDONLY)) == -1)
	{
		ft_putendl("ERROR: OPEN FD");
		exit(0);
	}
	return (fd);
}
