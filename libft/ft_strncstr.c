/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmariam <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 14:28:06 by fmariam           #+#    #+#             */
/*   Updated: 2019/04/16 14:40:25 by fmariam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncstr(const char *hay, const char *need, size_t n)
{
	size_t i;
	size_t j;
	size_t k;

	k = 0;
	if (*need == '\0')
		return (0);
	i = 0;
	while (hay[i] && i < n)
	{
		j = 0;
		while (hay[i + j] == need[j] && need[j] && i + j < n)
			j++;
		if (need[j] == '\0')
			k++;
		i++;
	}
	return (k);
}
