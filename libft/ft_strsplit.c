/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antini <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 14:13:01 by antini            #+#    #+#             */
/*   Updated: 2018/06/21 09:16:11 by antini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count(const char *s, char c)
{
	int			cnt;
	int			substr;

	substr = 0;
	cnt = 0;
	while (*s != '\0')
	{
		if (substr == 1 && *s == c)
			substr = 0;
		if (substr == 0 && *s != c)
		{
			substr = 1;
			cnt++;
		}
		s++;
	}
	return (cnt);
}

static int		ft_lenw(const char *s, char c)
{
	int			len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**splt;
	int			wrd;
	int			indx;

	indx = 0;
	if (!s || !c)
		return (NULL);
	wrd = ft_count((const char *)s, c);
	splt = (char **)malloc(sizeof(*splt) * (ft_count((const char *)s, c) + 1));
	if (splt == NULL)
		return (NULL);
	while (wrd--)
	{
		while (*s == c && *s != '\0')
			s++;
		splt[indx] = ft_strsub((const char *)s, 0, ft_lenw((const char *)s, c));
		if (splt[indx] == NULL)
			return (NULL);
		s = s + ft_lenw(s, c);
		indx++;
	}
	splt[indx] = NULL;
	return (splt);
}
