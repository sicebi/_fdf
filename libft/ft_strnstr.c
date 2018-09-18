/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antini <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 13:00:13 by antini            #+#    #+#             */
/*   Updated: 2018/06/18 13:09:52 by antini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	ln;

	if (*needle == '\0')
		return ((char *)haystack);
	ln = ft_strlen(needle);
	while (*haystack != '\0' && len-- >= ln)
	{
		if (*haystack == *needle && ft_memcmp(haystack, needle, ln) == 0)
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
