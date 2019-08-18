/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmariam <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:10:00 by fmariam           #+#    #+#             */
/*   Updated: 2019/05/04 19:42:40 by fmariam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, int n)
{
	int		len;
	char	*x;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(x = ft_strnew(len)))
		return (NULL);
	if (s1 && s2)
	{
		x = ft_strcat(x, s1);
		x = ft_strncat(x, s2, n);
	}
	return (x);
}
