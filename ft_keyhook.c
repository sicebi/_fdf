/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antini <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 08:04:52 by antini            #+#    #+#             */
/*   Updated: 2018/08/11 13:05:29 by antini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_keyhook_move(int keycode, t_mlx *e)
{
	if (keycode == 124 || keycode == 123)
	{
		e->movex = (keycode == 124) ? e->movex + 20 : e->movex - 20;
		mlx_clear_window(e->mlx, e->win);
		ft_draw_pixel(e);
	}
	if (keycode == 125 || keycode == 126)
	{
		e->movey = (keycode == 125) ? e->movey + 20 : e->movey - 20;
		mlx_clear_window(e->mlx, e->win);
		ft_draw_pixel(e);
	}
}

int				ft_keyhook(int keycode, t_mlx *e)
{
	ft_keyhook_move(keycode, e);
	if (keycode == 84 || keycode == 91)
	{
		e->zoom = (keycode == 78) ? e->zoom - 2 : e->zoom + 2;
		e->zoom = (e->zoom <= 0) ? 0 : e->zoom;
		mlx_clear_window(e->mlx, e->win);
		ft_draw_pixel(e);
	}
	if (keycode == 116 || keycode == 121)
	{
		e->key = (keycode == 116) ? e->key + 1 : e->key - 1;
		mlx_clear_window(e->mlx, e->win);
		ft_map_xyz(e, 0, 0, 0);
		ft_draw_pixel(e);
	}
	if (keycode == 53)
	{
		mlx_destroy_window(e->mlx, e->win);
		exit(EXIT_FAILURE);
	}
	return (0);
}
