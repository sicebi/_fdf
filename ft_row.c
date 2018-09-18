/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_row.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antini <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 16:57:15 by antini            #+#    #+#             */
/*   Updated: 2018/08/16 16:57:19 by antini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_row(char **map, int i)
{
	int		j;
	int		resul;

	j = 0;
	resul = 0;
	while (map[i][j] != '\0')
	{
		if (ft_isdigit(map[i][j]) == 1 && ft_isdigit(map[i][j + 1]) != 1)
		{
			resul++;
			while (map[i][j] != ' ' && map[i][j] != '\0')
				j++;
		}
		else
			j++;
	}
	return (resul);
}
