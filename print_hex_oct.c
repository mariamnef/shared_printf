/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_oct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmariam <fmariam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 13:27:43 by fmariam           #+#    #+#             */
/*   Updated: 2019/08/07 15:41:12 by fmariam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	strtolower(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
}

int         print_hex_oct(t_info *info)
{
    int     arg;
    char    *s;

    arg = va_arg(info->argp, int);
    s = ft_itoa_base(arg, 16);
    info->l = ft_strlen(s);
    deactivate_flags(info);
    if (info->flag & MINUS)
    {
        (info->flag & HASH && info->type == 'x') ? ft_putstr("0x") : 0;
        (info->flag & HASH && info->type == 'X') ? ft_putstr("0X") : 0;
        (info->type == 'x') ? strtolower(s) : 0;
        //do pres lahere !
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
        (info->flag & HASH && info->type == 'x') ? ft_putstr("0x") : 0;
        (info->flag & HASH && info->type == 'X') ? ft_putstr("0X") : 0;
        (info->type == 'x') ? strtolower(s) : 0;
        ft_putstr(s);
        info->count += info->l;
    }
    return (info->count);
}
// itoa base for negative numbers 