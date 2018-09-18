/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antini <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 14:10:37 by antini            #+#    #+#             */
/*   Updated: 2018/06/18 14:12:35 by antini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	begin;
	size_t	end;
	size_t	len;
	char	*str;

	if (!s)
		return (NULL);
	begin = 0;
	end = ft_strlen(s) - 1;
	while (begin < ft_strlen(s) && ft_isspace(s[begin]))
		begin++;
	while (end > begin && ft_isspace(s[end]))
		end--;
	len = end - begin + 1;
	str = ft_strsub(s, begin, len);
	return (str);
}
