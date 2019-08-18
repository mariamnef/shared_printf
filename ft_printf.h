/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmariam <fmariam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 11:53:05 by fmariam           #+#    #+#             */
/*   Updated: 2019/08/01 12:28:40 by fmariam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

# define MINUS 1
# define PLUS  2
# define ZERO  4
# define SPACE 8
# define HASH  16

typedef struct  s_info
{
    int     len;
    int     flag;
    int     precision;
    int     width;
    char    type;
    va_list argp;
}               t_info;

int	    ft_printf(char *s, ...);
char	*check_flags(char *s, t_info *info);
char	*get_flags(char *s, t_info *info);
void    print_int(t_info *info);
void    print_char(t_info *info);
void    print_octal(t_info *info);
void    print_string(t_info *info);
void    print_addr(t_info *info);

#endif