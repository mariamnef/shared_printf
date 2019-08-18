/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmariam <fmariam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 19:49:24 by fmariam           #+#    #+#             */
/*   Updated: 2019/08/07 15:41:52 by fmariam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		isflag(char c)
{
	if (c == '+' || c == '-' || c == '0' || c == ' ' || c == '#')
		return (1);
	return (0);
}
int		isconversion(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'o' ||
		c == 'u' || c == 'x' || c == 'X' || c == 'f')
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

// static	void	print_type(char *s, t_info *info)
// {
// 	if (info->type == 'd')
// 	{
// 		s = get_flags(s + 1, info);
// 		print_int(info);
// 	}
// 	else if (info->type == 'c')
// 	{
// 		s = get_flags(s + 1, info);
// 		print_char(info);
// 	}
// 	else if (info->type == 's')
// 	{
// 		s = get_flags(s + 1, info);
// 		print_str(info);
// 	}
// 	// if (info->type == 'p')
// 	// {
// 	// 	s = get_flags(s + 1, info);
// 	// 	print_addr(info);
// 	// }
// 	// if (info->type == 'o')
// 	// {
// 	// 	s = get_flags(s + 1, info);
// 	// 	print_octal(info);
// 	// }
// }

int 			ft_printf(char *s, ...)
{
	t_info info;

	va_start(info.argp, s);
	info.count = 0;
	while (*s)
	{
		if (*s == '%')
		{
			info.precision = 0;
			info.width = 0;
			info.flag = 0;
			info.p = 0;
			check_conversion(s + 1, &info);
			//print_type(s + 1, &info);
			if (info.type == 'd')
			{
				s = get_flags(s + 1, &info);
				print_int(&info);
			}
			else if (info.type == 'c')
			 {
				s = get_flags(s + 1, &info);
				print_char(&info);
			 }
			else if (info.type == 's')
			{
				s = get_flags(s + 1, &info);
				print_str(&info);
			}
			else if (info.type == 'x' || info.type == 'X')
			{
				s = get_flags(s + 1, &info);
				print_hex_oct(&info);
			}
		// 	if (info->type == 'o')
		// 		print_octal(info);
		// s++;
		}
		else
		{
			ft_putchar(*s);
			s++;
			info.count++;
		}
	}
	return (info.count);
}

int		main(void)
{
	int a;

	printf("abc [%#5.6x]\n", 160);
	ft_printf("abc [%#5.6x]\n", 160);
	// printf("%d\n", printf("abc [%5s] fanna [%c] [%d]\n", "mery",'a', 1997));
	// ft_printf("%d\n", ft_printf("abc [%5s] fanna [%c] [%d]\n", "mery", 'a', 1997));
	// printf("%d\n", printf("abc [%+c] fanna [%d]\n", 'a', 12));
	// ft_printf("%d\n", ft_printf("abc [%+c] fanna [%d]\n", 'a', 12));
	return (0);
}