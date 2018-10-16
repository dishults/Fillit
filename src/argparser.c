/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argparser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klouer <klouer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 22:26:16 by klouer            #+#    #+#             */
/*   Updated: 2018/01/04 14:20:46 by klouer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		ft_argparse(char **av)
{
	if (!ft_strncmp(av[1], "-cr\0", 4))
		return (2);
	else if (!ft_strncmp(av[1], "-cmr\0", 5))
		return (5);
	else if (!ft_strncmp(av[1], "-cm\0", 4))
		return (3);
	else if (!ft_strncmp(av[1], "-cfr\0", 5))
		return (4);
	else if (!ft_strncmp(av[1], "-c\0", 3))
		return (1);
	else if (!ft_strncmp(av[1], "-", 1))
	{
		ft_putstr("Available args :\n");
		ft_putstr("-cr : Sorted Random Color Mode\n");
		ft_putstr("-cm : Pretty Macro Color Mode\n");
		ft_putstr("-cfr : Full Random Color Mode\n");
		ft_putstr("-cmr : Random Pretty Color Mode\n");
	}
	return (0);
}

void	ft_argmode(t_res *res, int x, int y, unsigned int *rt)
{
	res->pretty = 0;
	if (res->mode == 3)
		ft_color_map1(res, x, y);
	else if (res->mode == 2)
		ft_aleasortedcolor(res, x, y, rt);
	else if (res->mode == 4)
		ft_aleacolor(res, x, y);
	else if (res->mode == 1)
		ft_aleasortedcolor(res, x, y, rt);
	else if (res->mode == 5)
	{
		res->pretty = 1;
		ft_aleasortedcolor(res, x, y, rt);
	}
}
