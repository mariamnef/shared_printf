/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmariam <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 11:53:55 by fmariam           #+#    #+#             */
/*   Updated: 2019/04/07 17:38:27 by fmariam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int i;
	int m;
	int fanna;

	i = 0;
	m = 0;
	fanna = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' ||
	str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		fanna = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		m = (m * 10) + str[i] - 48;
		i++;
	}
	return (m * fanna);
}
