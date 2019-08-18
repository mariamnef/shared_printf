/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmariam <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 22:29:14 by fmariam           #+#    #+#             */
/*   Updated: 2019/04/15 22:28:59 by fmariam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_count_num(int n)
{
	int		i;

	i = 0;
	if (n == 0)
		i++;
	else if (n < 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char	*x;
	int		j;
	int		k;

	k = 0;
	j = ft_count_num(n);
	if (!(x = ft_strnew(j)))
		return (NULL);
	if (n == -2147483648)
		return ((x = ft_strdup("-2147483648")));
	if (n < 0)
	{
		x[0] = '-';
		n = n * -1;
		k = 1;
	}
	j--;
	while (j >= 0)
	{
		if (k == 1 && j == 0)
			break ;
		x[j--] = n % 10 + 48;
		n = n / 10;
	}
	return (x);
}
