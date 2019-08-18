/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmariam <fmariam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 12:51:12 by fmariam           #+#    #+#             */
/*   Updated: 2019/08/04 13:25:20 by fmariam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     print_char(t_info *info)
{
    char c;

    c = va_arg(info->argp, int);
    if (info->flag & MINUS)
    {
        ft_putchar(c);
        info->count++;
        while (info->width-- > 1)
        {
            ft_putchar(' ');
            info->count++;
        }
    }
    else
    {
        while (info->width-- > 1)
        {
            ft_putchar(' ');
            info->count++;
        }
        ft_putchar(c);
        info->count++;
    }
    return (info->count);
}