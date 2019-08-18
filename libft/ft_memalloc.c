/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmariam <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:20:22 by fmariam           #+#    #+#             */
/*   Updated: 2019/04/08 14:44:16 by fmariam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*s;

	s = (unsigned char *)malloc(size);
	if (!s)
		return (NULL);
	else
		ft_bzero(s, size);
	return (s);
}
