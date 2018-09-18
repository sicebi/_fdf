/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antini <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 08:08:12 by antini            #+#    #+#             */
/*   Updated: 2018/08/11 12:49:28 by antini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_init_structmlx(t_mlx *e)
{
	e->xwin = 2500;
	e->ywin = 1250;
	e->zoom = 20;
	e->movex = 0;
	e->movey = 0;
	e->key = 0;
}

int				main(int argc, char **argv)
{
	t_mlx	e;

	if (argc == 2)
	{
		e.map = save_map(argv, &e);
		ft_init_structmlx(&e);
		ft_map_xyz(&e, 0, 0, 0);
		e.mlx = mlx_init();
		e.win = mlx_new_window(e.mlx, e.xwin, e.ywin, "FDF");
		ft_draw_pixel(&e);
		mlx_hook(e.win, 2, 0, ft_keyhook, &e);
		mlx_loop(e.mlx);
	}
	return (0);
}
