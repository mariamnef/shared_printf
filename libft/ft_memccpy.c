/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmariam <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 20:50:23 by fmariam           #+#    #+#             */
/*   Updated: 2019/04/12 01:41:37 by fmariam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*ds;
	unsigned char	*sr;

	sr = (unsigned char *)src;
	ds = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		ds[i] = sr[i];
		if (ds[i] == (unsigned char)c)
			return (ds + (i + 1));
		i++;
	}
	return (NULL);
}
