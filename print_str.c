/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmariam <fmariam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 14:13:29 by fmariam           #+#    #+#             */
/*   Updated: 2019/08/04 14:52:04 by fmariam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     print_str(t_info *info)
{
    char *s;

    s = va_arg(info->argp, char*);
    info->l = ft_strlen(s);
    if (info->flag & MINUS)
    {
        ft_putstr(s);
        info->count += info->l;
        while (info->width-- > info->l)
        {
            ft_putchar(' ');
            info->count++;
        }
    }
    else
    {
        while (info->width-- > info->l)
        {
            ft_putchar(' ');
            info->count++;
        }
        ft_putstr(s);
        info->count += info->l;
    }
    return (info->count);
}