/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmariam <fmariam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 22:15:41 by fmariam           #+#    #+#             */
/*   Updated: 2019/08/01 20:31:45 by fmariam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

void    print_int(t_info *info)
{   
    int s;
    int z;
    int l;
    int n;
    int x;

    n = va_arg(info->argp, int);
    l = ft_count_num(n);
    if (info->flag & PLUS)
    {
        l += 1;
        if (info->flag & SPACE)
            info->flag = info->flag & ~SPACE;
        ft_putchar('+');
    }
    if (info->flag & ZERO)
    {
        if (!(info->width))
            info->flag = info->flag & ~ZERO;
         else
         {
            while (info->width-- > l)
            ft_putnbr(0);
         }
    }
    if ((info->width && info->flag & ZERO) || info->precision)
    {
        while (info->width-- > l)
            ft_putnbr(0);
    }







    //apply x !!!!!
    // x = ((info->width && info->flag & ZERO) || info->precision < 0) ? '0' : ' ';
    // (info->flag & SPACE) ? s = 1 : 0;
    // if (l < info->precision && l < info->width)
    // {
    //     l = (info->precision <= info->width) ? info->width : info->precision;
    //     if ((info->width && info->flag & ZERO) || (info->precision))
    //         z = 1;
    //     //(info->flag & SPACE) ? s = 1 : 0;
    // }
    // if (l >= info->precision && l >= info->width)
    // {
    //     l = (s == 1) ? l + 1 : l;
    // }
    
    //str = (char *)malloc(sizeof(char) * len + 1);
    //ft_putstr(num);
    ft_putnbr(n);

}
