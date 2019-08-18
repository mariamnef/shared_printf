/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmariam <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 17:17:22 by fmariam           #+#    #+#             */
/*   Updated: 2019/04/15 13:45:12 by fmariam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_real_dstlen(char *s, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (s[i] == '\0')
			return (i);
		i++;
	}
	return (size);
}

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	si;
	size_t	di;

	dstlen = ft_real_dstlen(dst, size);
	srclen = ft_strlen(src);
	if (dstlen < size)
	{
		si = 0;
		di = dstlen;
		while (di < size && si < srclen)
			dst[di++] = src[si++];
		if (di < size)
			dst[di] = '\0';
		else
			dst[di - 1] = '\0';
	}
	return (dstlen + srclen);
}
