/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 14:43:27 by dshults           #+#    #+#             */
/*   Updated: 2017/12/22 14:43:29 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_put_tetris(t_res *res, t_block *t)
{
	int i;

	i = 0;
	while (i < 4)
	{
		res->map[res->y + t->y[i]][res->x + t->x[i]] = t->abcd;
		i++;
	}
}

int		ft_is_putable(t_res *res, t_block *t)
{
	int i;

	i = 0;
	if (res->x + t->w >= res->size || res->y + t->h >= res->size)
		return (0);
	while (i < 4)
	{
		if (res->map[res->y + t->y[i]][res->x + t->x[i]] != '.')
			return (0);
		i++;
	}
	return (1);
}
