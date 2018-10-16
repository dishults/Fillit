/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 14:43:37 by dshults           #+#    #+#             */
/*   Updated: 2017/12/22 14:43:43 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_place_it(t_res *res, int tetri)
{
	res->y = 0;
	while (res->y < res->size)
	{
		res->x = 0;
		while (res->x < res->size)
		{
			if (ft_is_putable(res, res->tab[tetri]) > 0)
			{
				ft_put_tetris(res, res->tab[tetri]);
				res->tab[tetri]->xmin = res->x;
				res->tab[tetri]->ymin = res->y;
				return (1);
			}
			res->x++;
		}
		res->y++;
	}
	return (0);
}

static void		ft_clear_it(t_res *res, int tetri)
{
	int			y;
	int			x;

	y = 0;
	while (y < res->size)
	{
		x = 0;
		while (x < res->size)
		{
			if (res->map[y][x] == 'A' + tetri)
				res->map[y][x] = '.';
			x++;
		}
		y++;
	}
}

static int		ft_move_it(t_res *res, int tetri)
{
	ft_clear_it(res, tetri);
	res->x = res->tab[tetri]->xmin + 1;
	res->y = res->tab[tetri]->ymin;
	while (res->y < res->size)
	{
		while (res->x < res->size)
		{
			if (ft_is_putable(res, res->tab[tetri]))
			{
				ft_put_tetris(res, res->tab[tetri]);
				res->tab[tetri]->xmin = res->x;
				res->tab[tetri]->ymin = res->y;
				return (1);
			}
			res->x++;
		}
		res->x = 0;
		res->y++;
	}
	return (0);
}

int				ft_solve(t_res *res, int tetri)
{
	if (tetri == res->t_nb)
		return (1);
	if (!ft_place_it(res, tetri))
		return (0);
	while (!ft_solve(res, tetri + 1))
	{
		if (!ft_move_it(res, tetri))
			return (0);
	}
	return (1);
}
