/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmariam <fmariam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 19:49:24 by fmariam           #+#    #+#             */
/*   Updated: 2019/08/01 19:54:25 by fmariam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		isflag(char c)
{
	if (c == '+' || c == '-' || c == '0' || c == ' ' || c == '#')
		return (1);
	return (0);
}
static	int		istype(char c)
{
	if (c == 'd' || c == 'c' || c == 's' || c == 'p' || c == 'o' || c == 'i' 
		|| c == 'u'|| c == 'x' || c == 'X' || c == 'f')
		return (1);
	return (0);
}
char			*check_flags(char *s, t_info *info)
{
	if (*s == '-')
		info->flag = info->flag | MINUS;
	if (*s == '+')
		info->flag = info->flag | PLUS;
	if (*s == '#')
		info->flag = info->flag | HASH;
	if (*s == '0')
		info->flag = info->flag | ZERO;
	if (*s == ' ')
		info->flag = info->flag | SPACE;

	s++;
	return (s);
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
		info->type = *s;
		if (info->type)
			break ;
		s++;
	}
	return (s + 1);
}

void	print_arg(t_info *info)
{

}

int 			ft_printf(char *s, ...)
{
	t_info info;

	va_start(info.argp, s);
	info.flag = 0;
	while (*s)
	{
		if (*s == '%')
		{
			s = get_flags(s + 1, &info);
			if (info.type == 'd')
				print_int(&info);
			// //printf("%c\n", *s);
			// if (info->type == 'c')
			// 	print_char(info);
			// if (info->type == 's')
			// 	print_string(info);
			// if (info->type == 'p')
			// 	print_addr(info);
			// if (info->type == 'o')
			// 	print_octal(info);
		//s++;
		}
		else
		{
			ft_putchar(*s);
			s++;
		}
	}
	return (1);
}

 int main()
{
	printf("abc %+05d\n", 10);
	//ft_printf("%d\n", 12);
	ft_printf("abc %+05d\n", 10);
	return (0);
}