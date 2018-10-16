/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 14:43:07 by dshults           #+#    #+#             */
/*   Updated: 2017/12/29 17:36:52 by klouer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_setup_map(t_res *res, int count, t_block **tab)
{
	int			size;
	int			space_needed;
	int			x;
	int			y;

	size = 0;
	res->t_nb = count;
	res->tab = tab;
	space_needed = count * 4;
	while (size * size < space_needed)
		size++;
	res->size = size;
	y = 0;
	while (y < 16)
	{
		x = 0;
		while (x < 16)
			res->map[y][x++] = '.';
		y++;
	}
}

static t_res	*ft_setup(t_block *t, size_t count)
{
	int			index;
	t_res		*map;
	t_block		**tab;

	index = 0;
	map = (t_res *)malloc(sizeof(t_res));
	tab = (t_block **)malloc(sizeof(t_block *) * count);
	if (!map || !tab)
		return (0);
	while (t)
	{
		tab[index] = t;
		t->abcd = index + 'A';
		index++;
		ft_get_tris(t);
		t = t->next;
	}
	ft_setup_map(map, count, tab);
	return (map);
}

static t_block	*ft_getbox(const char *content, size_t content_size)
{
	t_block		*t;

	t = (t_block *)malloc(sizeof(t_block));
	if (!t)
		return (0);
	t->content = ft_strndup(content, content_size);
	t->content_size = content_size;
	t->next = 0;
	t->w = 0;
	t->h = 0;
	return (t);
}

t_res			*ft_get(char *buf, size_t count, size_t size)
{
	t_block		*first;
	t_block		*list;
	t_res		*map;

	if (!buf)
		return (0);
	size = (ft_strlen(buf) + 1) / 21;
	count = size;
	list = ft_getbox(buf, 21);
	size--;
	first = list;
	buf += 21;
	while (size)
	{
		list->next = ft_getbox(buf, 21);
		list = list->next;
		size--;
		buf += 21;
	}
	map = ft_setup(first, count);
	return (map);
}
