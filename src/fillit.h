/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 14:44:57 by dshults           #+#    #+#             */
/*   Updated: 2018/01/04 14:29:50 by klouer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "../libft/libft.h"
# include "../libft/color.h"

typedef struct			s_block
{
	char				*content;
	size_t				content_size;
	struct s_block		*next;
	char				w;
	char				h;
	char				abcd;
	char				xmin;
	char				ymin;
	char				x[4];
	char				y[4];
}						t_block;

typedef struct			s_res
{
	char				map[16][16];
	char				size;
	char				x;
	char				y;
	int					t_nb;
	struct s_block		**tab;
	int					pretty;
	int					mode;
}						t_res;

int						ft_check_input(char *s);
t_res					*ft_get(char *buf, size_t count, size_t size);
void					ft_get_tris(t_block *t);

int						ft_solve(t_res *map, int tetri);

int						ft_is_putable(t_res *map, t_block *t);
void					ft_put_tetris(t_res *res, t_block *t);

void					ft_color_map(t_res *res, char **av);
unsigned int			ft_random(unsigned int startnumber, unsigned
							int endnumber);
int						*ft_randomtab(size_t size, int min, int max);
char					*ft_gencolorcode(unsigned int colorcode, char *string);
void					ft_aleacolor(t_res *res, int x, int y);
int						ft_checkargs(int argc, char *argv, char *arg);
void					ft_aleasortedcolor(t_res *res, int x, int y
							, unsigned int *rt);
int						*ft_genpremadecolortab(void);
void					ft_color_map1(t_res *res, int x, int y);
void					ft_color_map2(t_res *res, int x, int y);
void					ft_color_map3(t_res *res, int x, int y);
int						ft_argparse(char **av);
void					ft_argmode(t_res *res, int x, int y
							, unsigned int *rt);
void					ft_show_res(t_res *res, int arg, char **av);
unsigned int			*ft_readrandomtab(size_t size, int fd);
int						*ft_asciitoid(int n);
char					*ft_genprettycolorcode(unsigned int colorcode
							, char *string);

# define BUF_SIZE 4096

#endif
