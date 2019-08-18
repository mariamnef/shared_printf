/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmariam <fmariam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 23:52:00 by fmariam           #+#    #+#             */
/*   Updated: 2019/08/05 21:14:44 by fmariam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    deactivate_flags(t_info *info)
{
    if (info->flag & PLUS)
    {
        info->l += 1;
        if (info->flag & SPACE)
            info->flag = info->flag & ~SPACE;
        if (info->precision)
            info->precision += 1;
    }
	info->flag = (info->sign == 1) ?  info->flag & ~PLUS : info->flag;
    if (info->flag & ZERO)
    {
        info->flag = (info->flag & MINUS) ? info->flag & ~ZERO : info->flag;
        info->flag = (info->precision) ? info->flag & ~ZERO : info->flag;
        info->flag = (!(info->width)) ? info->flag & ~ZERO : info->flag;
    }
	if (info->flag & HASH)
	{
		if (info->type == 'x' || info->type == 'X')
			info->width -= 2;
	}
}

int		minus_with_both(t_info *info, int arg)
{	
	int c;

	c = info->precision;
	(info->sign == 1) ? ft_putchar('-') : 0;
	info->count += info->l;
	while (info->precision++ < info->width && info->l++ < c)
	{
            ft_putnbr(0);
			info->count++;
	}
        ft_putnbr(arg);
		//info->count += info->l;
	(info->sign == 1) ? info->width-- : 0;
    while (c++ < info->width)
	{
        ft_putchar(' ');
		info->count++;
	}
	return (info->count);
}

int    minus_is_on(t_info *info, int arg)
{

    (info->flag & PLUS) ? ft_putchar('+') :0;
    (info->flag & SPACE && info->sign == 0) ? ft_putchar(' ') :0;
    if ((info->precision && !(info->width)) || info->precision >= info->width)
    {
		if (info->sign == 1)
		{
			ft_putchar('-');
			info->l -= 1;
		}
        while (info->precision-- > info->l)
            ft_putnbr(0);
        ft_putnbr(arg);
    }
    else if (info->width && !info->precision)
    {	
		(info->sign == 1) ? ft_putchar('-') : 0;
        info->width = (info->flag & PLUS) ? info->width-- : info->width;
        ft_putnbr(arg);
        while (info->l++ < info->width)
            ft_putchar(' ');
    }
    else if (info->width > info->precision)
    	minus_with_both(info, arg);
    return (info->count);
}

char 			*get_flags(char *s, t_info *info)
{
	while (isflag(*s))
		s = check_flags(s, info);
	while (*s)
	{
		if (ft_isdigit(*s))
		{
			info->width = ft_atoi(s);
			while (ft_isdigit(*s))
				s++;
		}
		if (*s == '.')
		{
			s++;
			if (ft_isdigit(*s))
			{
				info->precision = ft_atoi(s);
				while (ft_isdigit(*s))
					s++;
			}
		}
		if (info->type)
			break ;
		s++;
	}
	return (s + 1);
}

// int		isconversion(char c)
// {
// 	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'o' ||
// 		c == 'u' || c == 'x' || c == 'X' || c == 'f')
// 		return (1);
// 	return (0);
// }

void	check_conversion(char *s, t_info *info)
{
	while (!(isconversion(*s)))
		s++;
	info->type = *s;
}