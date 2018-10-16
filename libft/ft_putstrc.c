/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klouer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 06:46:34 by klouer            #+#    #+#             */
/*   Updated: 2017/12/28 14:30:48 by klouer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include "color.h"

void	ft_putstrc(char *str, char *color, size_t len)
{
	ft_putstr(color);
	write(1, str, len);
	ft_putstr(RESET);
}
