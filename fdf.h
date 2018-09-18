/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antini <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 09:18:12 by antini            #+#    #+#             */
/*   Updated: 2018/08/11 12:44:02 by antini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	int		xwin;
	int		ywin;
	int		colum;
	int		zoom;
	int		movex;
	int		movey;
	int		color;
	int		varx;
	int		vary;
	int		key;
	int		**mapxyz;
	char	**map;
}				t_mlx;

typedef struct	s_draw
{
	int		startx;
	int		starty;
	int		endxx;
	int		endxy;
	int		endyx;
	int		endyy;
}				t_draw;

void			ft_map_xyz(t_mlx *e, int y, int x, int i);
void			ft_draw_pixel(t_mlx *e);
void			ft_draw(int endx, int endy, t_mlx *e, t_draw *d);
int				ft_row(char **map, int i);
int				ft_keyhook(int keycode, t_mlx *e);
char			**save_map(char **argv, t_mlx *e);
#endif
