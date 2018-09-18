/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antini <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 13:14:02 by antini            #+#    #+#             */
/*   Updated: 2018/06/19 08:54:30 by antini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *hay, const char *nee)
{
	int i;
	int matches;

	i = 0;
	if (nee[0] == '\0')
		return ((char *)hay);
	while (hay[i] != '\0')
	{
		matches = 0;
		while (nee[matches] == hay[i + matches] && nee[matches] != '\0')
			matches++;
		if (nee[matches] == '\0')
			return ((char *)(hay + i));
		i++;
	}
	return (NULL);
}
