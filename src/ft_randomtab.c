/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomtab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klouer <klouer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 18:31:32 by klouer            #+#    #+#             */
/*   Updated: 2018/01/04 14:22:43 by klouer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>
#include <stdio.h>

int					*ft_randomtab(size_t size, int min, int max)
{
	int				*rtab;
	size_t			i;

	if ((rtab = (int *)malloc(size * sizeof(int)) + 1) == NULL)
		return (0);
	i = 0;
	while (i < size)
	{
		rtab[i] = ft_random(min, max);
		if (rtab[i] > 240)
			rtab[i] = rtab[i] % 70;
		i++;
	}
	rtab[i] = '\0';
	return (rtab);
}

unsigned int		*ft_readrandomtab(size_t size, int fd)
{
	int				ret;
	char			*buf;
	unsigned int	*test;
	size_t			i;
	unsigned char	tab[100];

	if ((fd = open("/dev/random", O_RDONLY)) < 0)
		return (NULL);
	buf = NULL;
	ret = read(fd, tab, size);
	i = 0;
	if ((buf = malloc(sizeof(char) * size + 1)) == NULL)
		return (NULL);
	if ((test = malloc(sizeof(unsigned int) * size + 1)) == NULL)
		return (NULL);
	while (i < size)
	{
		buf[i] = (0xffff & tab[i]);
		buf[i] = (unsigned char)buf[i];
		test[i] = (unsigned char)buf[i];
		i++;
	}
	free(buf);
	return (test);
}

int					*ft_asciitoid(int n)
{
	unsigned int	tmp;
	unsigned int	length;
	int				*ret;

	ret = NULL;
	length = 1;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	tmp = n;
	while ((tmp /= 10) > 0)
	{
		length *= 10;
	}
	tmp = n;
	while (length)
	{
		*ret = (char)(tmp / length) + 48;
		tmp %= length;
		length /= 10;
	}
	return (ret);
}
