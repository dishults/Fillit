/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klouer <klouer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 01:36:38 by klouer            #+#    #+#             */
/*   Updated: 2018/01/04 14:24:47 by klouer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdint.h>
#include <fcntl.h>
#include <stdio.h>

/*
**─────────────────▄▄▄▄▄▄▄▄▄▄▄
**────────────▄▄▀▀▀░░░░░░░░░░░▀▄▄
**────────▄▄▀▀░░░░░░░▄▄▄▄▄▄▄░░░░░▀▄
**──────▄▀░░░░░░░░░▄▄▄▄▄▄▄▄▄▄▄░░░░░█
**────▄▀░░░░░▄▄▄▄▄▄▄░░░░░░░░░░░▄▄▄▄▄█▄▄
**───▄▀░▐▌░░░░░░░░░░▀▀░░░░░░░▀▀░░░░░░█
**──█░░░▀░░░░░░░▄▀▀▀▄░░░░▄░░░░▄▀▀▀▄░░▐▌
**─█░░░░░░▄▄▄░░▐░░▄░░▌░░░░▀▄░▐░░▄░░▌░░█
**▐▌░░░░▀▀░░░░▄░▀▄▄▄▀░░░░░░░▌░▀▄▄▄▀░░░▐▌
**█░░░░░░░░░░░░▀▄▄▄░░░░░░░░▐░░░░░▄▄▄▀░░█
**█░░░░▄▀░░░░░░░▄▄░░░░░░▄▀░▐░░░▄▄░░░░░░█
**▐▌░░▀░░░░░░░▄▀░░░▐▀░░░░░░░▀▌░░░▀▄░░░░█
**▐▌░░░▐░░░░░▐▌░░░░░▀█░░░░░░░▌░░░░█░░░░█
**─█░░░░░░░░░░░░░░▄░░▀▀▄▄▄▄▀▀░▀▄░░░░░░░█
**─▐▌░░░░░░░░░░░▄▀░░░░▄▄▄▄▄▄░░░░▌░░░░░░█
**──█░░░░░░░░░░▐░░░░▄▀░░░░░░▀▄░░▌░░░░░▐▌
**──▐▌░░░░░░░░░▐░░░░▀░░░▀▀░░░▀░░░░░░░░█
**───█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▐▌
**───▐▌░░░░░░░░░▄███████▄░░░░▄████████▄
**────▀▄████████████▀█████▄▄████████▀██
**───▄██▀▄░░░░░███▀▄██████▀▀██████▀▄███
**───▀▀───▀▀▀▀▀▀█████████▀▀▀▀█████████▀
**───────────────▀▀▀▀▀▀▀──────▀▀▀▀▀▀▀
** Hello fellow corrector, you may ask how the fuck does this work ?
** Well it's pretty simple, we have here a 16 bit binary string.
** The first bit is connected to the last bit, and the
** 11th, 13th, 14th and 16th bits are connected together by XOR gates.
** The +1 at the end of the XOR operations is simply the first bit,
** which is x^0, and that makes 1.
** The output of this operation is then set as the first bit of the string,
** which pushes every bit and pushes the last bit out of the 16 bit string,
** thus creating some randomness. Now this is not implemented perfectly,
** and this is far from exact science (this is an actual popular algorithm
** called a Fibonacci LFSR), and my implementation is not random enough,
** only sometimes..
** My "seed" here is the memory adress pointed by p, and this is the main
** reason it does not always work perfectly. Room for improvement !
** UPDATE : This is no longer in use, too unreliable for now.
*/

unsigned int	ft_random(unsigned int startnumber, unsigned int endnumber)
{
	uint16_t			bit;
	uint16_t			t;
	static unsigned int	lfsr = 0x00ff;
	int					*p;

	p = NULL;
	t = 0;
	if (startnumber == endnumber)
		return (startnumber);
	if ((p = (int *)malloc(sizeof(*p))) == NULL)
		return (0);
	t = t ^ (int)p;
	bit = ((lfsr >> 0) ^ (lfsr >> 2) ^ (lfsr >> 3) ^ (lfsr >> 5)) & 1;
	lfsr = ((bit << 15) | (lfsr >> 1) | t) % endnumber;
	while (lfsr < startnumber)
	{
		lfsr = lfsr + endnumber - startnumber;
	}
	free(p);
	return (lfsr);
}

void			ft_aleasortedcolor(t_res *res, int x, int y, unsigned int *rt)
{
	int					sortedcolor;
	char				*tr;

	tr = NULL;
	sortedcolor = res->map[y][x] - 64;
	if (res->pretty == 1)
		tr = ft_genprettycolorcode(rt[sortedcolor], &res->map[y][x]);
	else
		tr = ft_gencolorcode(rt[sortedcolor], &res->map[y][x]);
	ft_putstr(tr);
	tr = NULL;
}

void			ft_aleacolor(t_res *res, int x, int y)
{
	unsigned int		*rand;
	char				*tk;

	rand = ft_readrandomtab(2, 0);
	if (res->map[y][x] == '\n' && res->map[y][x + 1] != '\0')
	{
		ft_putchar('\n');
		return ;
	}
	tk = ft_gencolorcode(rand[1], &res->map[y][x]);
	ft_putstr(tk);
}

/*
**───────▄██████████████████▄───────
**────▄███████████████████████▄─────
**───███████████████████████████────
**──█████████████████████████████───
**─████████████▀─────────▀████████──
**██████████▀───────────────▀██████─
**███████▀────────────────────█████▌
**██████───▄▀▀▀▀▄──────▄▀▀▀▀▄──█████
**█████▀──────────────────▄▄▄───████
**████────▄█████▄───────▄█▀▀▀█▄──██▀
**████──▄█▀────▀██─────█▀────────█▀─
**─▀██───────────▀────────▄███▄──██─
**──██───▄▄██▀█▄──▀▄▄▄▀─▄██▄▀────███
**▄███────▀▀▀▀▀──────────────▄▄──██▐
**█▄▀█──▀▀▀▄▄▄▀▀───────▀▀▄▄▄▀────█▌▐
**█▐─█────────────▄───▄──────────█▌▐
**█▐─▀───────▐──▄▀─────▀▄──▌─────██▐
**█─▀────────▌──▀▄─────▄▀──▐─────██▀
**▀█─█──────▐─────▀▀▄▀▀─────▌────█──
**─▀█▀───────▄────────────▄──────█──
**───█─────▄▀──▄█████████▄─▀▄───▄█──
**───█────█──▄██▀░░░░░░░▀██▄─█──█───
**───█▄───▀▄──▀██▄█████▄██▀─▄▀─▄█───
**────█▄────▀───▀▀▀▀──▀▀▀──▀──▄█────
**─────█▄────────▄▀▀▀▀▀▄─────▄█─────
**──────███▄──────────────▄▄██──────
**─────▄█─▀█████▄▄────▄▄████▀█▄─────
**────▄█───────▀▀██████▀▀─────█▄────
**───▄█─────▄▀───────────▀▄────█▄───
**──▄█─────▀───────────────▀────█▄──
**──────────────────────────────────
**▐▌▐█▄█▌▐▀▀█▐▀▀▌─█▀─█▀─▐▌▐▀█▐▀█─█─█
**▐▌▐─▀─▌▐▀▀▀▐──▌─▀█─▀█─▐▌▐▀▄▐▀▄─█─█
**▐▌▐───▌▐───▐▄▄▌─▄█─▄█─▐▌▐▄█▐─█─█▄█
*/
