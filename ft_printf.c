/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 21:29:12 by cyun              #+#    #+#             */
/*   Updated: 2022/08/10 23:46:10 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		print_len;
	va_list	ap;
	char	*first;

	print_len = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			first = (char *)str;
			if (*(++str))
				print_len += ft_parse((char *)str, ap);
			while (*str && !ft_strchr(SPECIFIERS, *str))
				str++;
			if (!(*str))
				str = first;
		}
		else
			print_len += ft_printchar(*str);
		if (*str)
			str++;
	}
	va_end(ap);
	return (print_len);
}

int	ft_print_format(t_format f, va_list ap)
{
	int	print_len;

	print_len = 0;
	if (f.specifier == 'c' || f.specifier == '%')
		print_len = ft_print_c_pct(f, ap);
	if (f.specifier == 's')
		print_len = ft_print_s(f, ap);
	if (f.specifier == 'd' || f.specifier == 'i' || f.specifier == 'u')
		print_len = ft_print_d_i_u(f, ap);
	if (f.specifier == 'X' || f.specifier == 'x')
		print_len = ft_print_x(f, ap);
	if (f.specifier == 'p')
		print_len = ft_print_p(f, ap);
	return (print_len);
}
