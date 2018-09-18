/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antini <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 14:35:44 by antini            #+#    #+#             */
/*   Updated: 2018/07/05 11:46:31 by antini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_newline(char *buff)
{
	int i;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\n')
		return (1);
	return (0);
}

int		get_line(const int fd, char *buf, char *strs[fd])
{
	int		data;
	char	*temp;

	while ((ft_newline(buf) != 1) && ((data = read(fd, buf, BUFF_SIZE)) > 0))
	{
		buf[data] = '\0';
		temp = strs[fd];
		strs[fd] = ft_strjoin(temp, buf);
		ft_strdel(&temp);
	}
	ft_strdel(&buf);
	if (data < 0)
		return (-1);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	int			data;
	static char	*strs[2147483647];
	char		*buff;
	char		*str;
	char		*temp;

	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	buff = ft_strnew(BUFF_SIZE);
	if (!strs[fd])
		strs[fd] = ft_strnew(0);
	if ((data = get_line(fd, buff, strs)) == -1)
		return (-1);
	if ((str = ft_strchr(strs[fd], '\n')))
	{
		*line = ft_strsub(strs[fd], 0, str - strs[fd]);
		temp = strs[fd];
		strs[fd] = ft_strdup(str + 1);
		ft_strdel(&temp);
		return (1);
	}
	*line = ft_strdup(strs[fd]);
	ft_strdel(&strs[fd]);
	return (ft_strlen(*line) > 0 ? 1 : 0);
}
