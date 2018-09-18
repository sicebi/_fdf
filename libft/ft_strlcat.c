/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antini <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 13:49:53 by antini            #+#    #+#             */
/*   Updated: 2018/06/18 14:02:08 by antini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char		*cr;
	char		*redr;
	size_t		l;

	cr = (char *)ft_memchr(dst, '\0', dstsize);
	if (cr == NULL)
		return (dstsize + ft_strlen(src));
	redr = (char *)src;
	l = (size_t)(cr - dst) + ft_strlen(redr);
	while ((size_t)(cr - dst) < dstsize - 1 && *redr != '\0')
	{
		*cr = *redr;
		cr++;
		redr++;
	}
	*cr = '\0';
	return (l);
}
