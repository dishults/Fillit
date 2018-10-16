/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klouer <klouer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 06:36:49 by klouer            #+#    #+#             */
/*   Updated: 2017/12/30 13:49:30 by klouer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>
#include <stdio.h>

void		ft_show_res(t_res *res, int arg, char **av)
{
	int		y;
	int		x;

	if (arg == 2)
	{
		ft_color_map(res, av);
		return ;
	}
	y = 0;
	while (y < res->size)
	{
		x = 0;
		while (x < res->size)
		{
			ft_putchar(res->map[y][x]);
			x++;
		}
		y++;
		ft_putchar('\n');
	}
}

static void	ft_put_error(int err)
{
	if (err == 2)
	{
		ft_putstr("Usage: ./fillit (arg) [mapfile]\n");
		exit(0);
	}
	else if (err == 0)
	{
		ft_putstr("error\n");
		exit(0);
	}
}

int			main(int ac, char **av)
{
	t_res	*res;
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];
	int		arg;

	arg = 1;
	if (ac == 3 && ft_argparse(av))
		arg = 2;
	else if (ac != 2)
		ft_put_error(2);
	fd = open(av[arg], O_RDONLY);
	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	if (!(ft_check_input(buf)))
		ft_put_error(0);
	res = ft_get(buf, 0, 0);
	if (res == 0)
		ft_put_error(0);
	while (!ft_solve(res, 0))
		res->size++;
	ft_show_res(res, arg, av);
	free(res);
	close(fd);
	exit(0);
}
