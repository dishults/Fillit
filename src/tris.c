/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tris.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 14:43:53 by dshults           #+#    #+#             */
/*   Updated: 2017/12/22 14:43:55 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_get_size(t_block *t)
{
	int		i;
	int		max;

	i = 0;
	max = 0;
	while (i < 4)
	{
		if (t->x[i] > max)
			max = t->x[i];
		i++;
	}
	t->w = max;
	i = 0;
	max = 0;
	while (i < 4)
	{
		if (t->y[i] > max)
			max = t->y[i];
		i++;
	}
	t->h = max;
}

static void	ft_align_tris(t_block *t)
{
	int		i;
	int		x1;
	int		y1;

	i = 0;
	x1 = t->x[i];
	y1 = t->y[i];
	while (i != 4)
	{
		if (t->x[i] < x1)
			x1 = t->x[i];
		if (t->y[i] < y1)
			y1 = t->y[i];
		i++;
	}
	i = 0;
	while (i != 4)
	{
		t->x[i] = t->x[i] - x1;
		t->y[i] = t->y[i] - y1;
		i++;
	}
	ft_get_size(t);
}

void		ft_get_tris(t_block *t)
{
	int		x;
	int		y;
	int		i;

	x = 0;
	y = 0;
	i = 0;
	while (x < 4)
	{
		y = 0;
		while (y / 5 < 4)
		{
			if (t->content[y + x] == '#')
			{
				t->x[i] = x;
				t->y[i] = y / 5;
				i++;
			}
			y += 5;
		}
		x++;
	}
	ft_align_tris(t);
}
