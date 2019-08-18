/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmariam <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 20:28:55 by fmariam           #+#    #+#             */
/*   Updated: 2019/04/15 23:26:05 by fmariam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *need, size_t len)
{
	size_t i;
	size_t j;

	if (*need == '\0')
		return ((char *)hay);
	i = 0;
	while (hay[i] && i < len)
	{
		j = 0;
		while (hay[i + j] == need[j] && hay[i + j] && i + j < len)
		{
			j++;
			if (!need[j])
				return ((char *)hay + i);
		}
		i++;
	}
	return (NULL);
}
