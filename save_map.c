/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antini <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 11:39:12 by antini            #+#    #+#             */
/*   Updated: 2018/08/11 12:33:07 by antini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_check_line(char *line)
{
	int		j;

	j = 0;
	if (ft_strlen(line) <= 0)
		exit(EXIT_FAILURE);
	while (line[j] != '\0')
	{
		if (ft_isdigit(line[j]))
			while (line[j] != ' ' && line[j] != '\0')
				j++;
		if (line[j] == '\0')
			return ;
		if (!(ft_isdigit(line[j]) ||
		(line[j] == '-' && ft_isdigit(line[j + 1])) || line[j] == ' '))
			exit(EXIT_FAILURE);
		j++;
	}
}

char			**save_map(char **av, t_mlx *e)
{
	int		fd;
	int		colum;
	char	*line;
	char	*mapjoin;
	char	**map;

	fd = open(av[1], O_RDONLY);
	colum = 0;
	mapjoin = "\0";
	e->colum = 0;
	while (get_next_line(fd, &line) > 0)
	{
		ft_check_line(line);
		mapjoin = ft_strjoin(mapjoin, line);
		mapjoin = ft_strjoin(mapjoin, "\n");
		e->colum++;
	}
	if (e->colum == 0)
		exit(EXIT_FAILURE);
	if (get_next_line(fd, &line) == -1)
		exit(EXIT_FAILURE);
	map = ft_strsplit(mapjoin, '\n');
	return (map);
}
