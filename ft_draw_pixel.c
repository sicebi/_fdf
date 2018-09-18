/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antini <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 06:50:10 by antini            #+#    #+#             */
/*   Updated: 2018/08/11 12:48:33 by antini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_color(t_mlx *e, int y, int x)
{
	if (e->mapxyz[y][x] < 0)
		return (0xAA2200);
	else if (e->mapxyz[y][x] > 0)
		return (0x0000FF);
	else
		return (0xFFFFFF);
}

static void		ft_init_structdraw(t_draw *d, int x, int y, t_mlx *e)
{
	d->startx = 0.71 * (x - y) * e->zoom;
	d->starty = ((0.4 * (x + y) - 0.52 * e->mapxyz[y][x]) * e->zoom);
	d->endxx = (0.71 * (x + 1 - y) * e->zoom);
	d->endxy = (0.71 * (x - (y + 1)) * e->zoom);
	d->endyx = ((0.4 * (x + 1 + y) - 0.52 * e->mapxyz[y][x + 1]) * e->zoom);
	if (y < e->colum - 1)
		d->endyy = ((0.4 * (x + 1 + y) - 0.52 * e->mapxyz[y + 1][x]) * e->zoom);
}

static void		ft_check_draw(t_mlx *e, t_draw *d, int y, int x)
{
	int		cx;
	int		cy;

	cx = (x < ft_row(e->map, y) - 1) ? 1 : 0;
	cy = (y < e->colum - 1 && x < ft_row(e->map, y + 1)) ? 1 : 0;
	if (cx == 1 && e->mapxyz[y][x] < e->mapxyz[y][x + 1])
	{
		e->color = ft_color(e, y, x + 1);
		ft_draw(d->endxx, d->endyx, e, d);
	}
	if (cx == 1 && e->mapxyz[y][x] >= e->mapxyz[y][x + 1])
	{
		e->color = ft_color(e, y, x);
		ft_draw(d->endxx, d->endyx, e, d);
	}
	if (cy == 1 && e->mapxyz[y][x] < e->mapxyz[y + 1][x])
	{
		e->color = ft_color(e, y + 1, x);
		ft_draw(d->endxy, d->endyy, e, d);
	}
	if (cy == 1 && e->mapxyz[y][x] >= e->mapxyz[y + 1][x])
	{
		e->color = ft_color(e, y, x);
		ft_draw(d->endxy, d->endyy, e, d);
	}
}

void			ft_draw_pixel(t_mlx *e)
{
	int		y;
	int		x;
	t_draw	d;

	y = 0;
	while (y < e->colum)
	{
		x = 0;
		while (x < ft_row(e->map, y))
		{
			ft_init_structdraw(&d, x, y, e);
			ft_check_draw(e, &d, y, x);
			x++;
		}
		y++;
	}
}
