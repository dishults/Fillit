/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   premadecolortab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klouer <klouer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 17:17:47 by klouer            #+#    #+#             */
/*   Updated: 2017/12/29 17:28:27 by klouer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	*ft_genpremadecolortab(void)
{
	int	*tab;
	int	i;
	int color;

	if ((tab = malloc(sizeof(int) * 27)) == NULL)
		return (0);
	i = 0;
	color = 25;
	while (i < 27)
	{
		tab[i] = color;
		i++;
		color += 7;
	}
	return (tab);
}
