/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antini <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 11:27:39 by antini            #+#    #+#             */
/*   Updated: 2018/06/21 09:13:58 by antini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_length(int n, size_t *len, int *weight)
{
	*len = 1;
	if (n >= 0)
	{
		*len = 0;
		n = -n;
	}
	*weight = 1;
	while (n / *weight < -9)
	{
		*weight *= 10;
		*len += 1;
	}
}

char			*ft_itoa(int n)
{
	size_t	l;
	int		wght;
	size_t	car;
	char	*s;

	ft_length(n, &l, &wght);
	s = (char *)malloc(sizeof(char) * (l + 1));
	if (s == NULL)
		return (NULL);
	car = 0;
	if (n < 0)
	{
		s[car] = '-';
		car++;
	}
	if (n > 0)
		n = -n;
	while (wght >= 1)
	{
		s[car++] = -(n / wght % 10) + 48;
		wght /= 10;
	}
	s[car] = '\0';
	return (s);
}
