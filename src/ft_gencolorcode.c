/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gencolorcode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klouer <klouer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 18:48:44 by klouer            #+#    #+#             */
/*   Updated: 2017/12/30 16:58:18 by klouer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

char	*ft_gencolorcode(unsigned int colorcode, char *string)
{
	char	*c;
	char	*ret;

	c = ft_itoa(colorcode);
	ret = ft_strndup("\x1b[38;5;", (ft_strlen(
										c) + ft_strlen(
											"\x1b[38;5;") + ft_strlen(
											"\x1b[0m") + ft_strlen("m")
									+ 1));
	ft_strcat(ret, c);
	free(c);
	ft_strcat(ret, "m");
	ft_strncat(ret, string, 1);
	ft_strcat(ret, "\x1b[0m");
	return (ret);
}

char	*ft_genprettycolorcode(unsigned int colorcode, char *string)
{
	char	*c;
	char	*ret;

	c = ft_itoa(colorcode);
	ret = ft_strndup("\x1b[38;5;", (ft_strlen(
										c) + ft_strlen(
											"\x1b[38;5;") + ft_strlen(
											"\x1b[0m") + ft_strlen("m")
									+ 1));
	ft_strcat(ret, c);
	free(c);
	ft_strcat(ret, "m");
	if (!ft_strncmp(string, ".", 1))
		ft_strncat(ret, "· ", 3);
	else
		ft_strncat(ret, "\u25A0 ", 6);
	ft_strcat(ret, "\x1b[0m");
	return (ret);
}
