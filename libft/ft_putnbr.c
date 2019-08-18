/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmariam <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 01:23:48 by fmariam           #+#    #+#             */
/*   Updated: 2019/04/16 12:34:47 by fmariam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long number;

	number = n;
	if (n < 0)
	{
		number *= -1;
		ft_putchar('-');
	}
	if (number > 9)
		ft_putnbr(number / 10);
	ft_putchar(number % 10 + 48);
}
