/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_xy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antini <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 13:41:21 by antini            #+#    #+#             */
/*   Updated: 2018/08/11 13:51:28 by antini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_map_xy_struct(t_mlx *e)
{
	int		y;

	y = 0;
	if (!(e->mapxyz = (int **)malloc((e->colum + 1) * sizeof(int *))))
		exit(EXIT_FAILURE);
	while (y < e->colum)
	{
		e->mapxyz[y] = (int *)malloc(ft_row(e->map, y) * sizeof(int));
		if (!(e->mapxyz[y]))
			exit(EXIT_FAILURE);
		y++;
	}
}

void			ft_map_xyz(t_mlx *e, int y, int x, int i)
{
	ft_map_xy_struct(e);
	while (y < e->colum)
	{
		i = 0;
		x = 0;
		while (e->map[y][i] != '\0')
		{
			if (ft_isdigit(e->map[y][i]) == 1 || e->map[y][i] == '-')
			{
				e->mapxyz[y][x] = ft_atoi(&e->map[y][i]);
				e->mapxyz[y][x] += (e->mapxyz[y][x] != 0) ? e->key : 0;
				x++;
				if (e->map[y][i] == '-')
					i++;
				while (ft_isdigit(e->map[y][i]) == 1)
					i++;
				while (e->map[y][i] != ' ' && e->map[y][i] != '\0')
					i++;
			}
			else
				i++;
		}
		y++;
	}
}
