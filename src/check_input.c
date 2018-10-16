/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 14:42:54 by dshults           #+#    #+#             */
/*   Updated: 2017/12/22 14:42:56 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_check_box_shape(char *s)
{
	int		n;

	n = 4;
	if ((ft_strlen(s) + 1) % 21 != 0 || (ft_strlen(s) + 1) / 21 > 26)
		return (0);
	while (s[n])
	{
		if (s[n] == '\n' && s[n + 5] == '\n' && s[n + 10] == '\n'
		&& s[n + 15] == '\n' && (s[n + 16] == '\n' || s[n + 16] == '\0'))
			n += 21;
		else
			return (0);
	}
	return (1);
}

static int	ft_check_tetriminos(char *s, int i, int pair)
{
	if (i % 21 > 14 && i % 21 < 19)
	{
		if (s[i + 1] == '#')
			pair++;
	}
	else if (s[i + 1] == '#')
	{
		if (s[i + 5] == '#' && s[i + 6] != '#')
			pair++;
		pair++;
	}
	else if (s[i + 5] == '#')
		pair++;
	return (pair);
}

static int	ft_is_last_line(char *s, int i, int *pair)
{
	if (s[i] == '\n' && s[i + 1] == '\0')
	{
		if (*pair == 3)
			return (1);
	}
	else if (s[i] == '\n' && s[i + 1] == '\n')
	{
		if (*pair != 3)
			return (0);
		else
		{
			*pair = 0;
		}
	}
	return (2);
}

int			ft_check_input(char *s)
{
	int		i;
	int		pair;
	int		res;

	i = 0;
	pair = 0;
	if (ft_check_box_shape(s) == 0)
		return (0);
	while (s[i])
	{
		res = ft_is_last_line(s, i, &pair);
		if (res == 0 || res == 1)
			return (res);
		else if (s[i] == '#')
		{
			pair = ft_check_tetriminos(s, i, pair);
			i++;
		}
		else if (s[i] == '.' || s[i] == '\n')
			i++;
		else
			return (0);
	}
	return (0);
}
