/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 01:42:42 by cyun              #+#    #+#             */
/*   Updated: 2022/08/05 01:45:47 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	ap;
	char	*first;

	count = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			first = (char *)str;
			if (*(++str))
				count += ft_parse((char *)str, ap);
			while (*str && !ft_strchr(SPECIFIERS, *str))
				str++;
			if (!(*str))
				str = first;
		}
		else
			count += ft_printchar(*str);
		if (*str)
			str++;
	}
	va_end(ap);
	return (count);
}

int	ft_print_format(t_format f, va_list ap)
{
	int	count;

	count = 0;
	if (f.specifier == 'c' || f.specifier == '%')
		count = ft_print_c_pct(f, ap);
	if (f.specifier == 's')
		count = ft_print_s(f, ap);
	if (f.specifier == 'd' || f.specifier == 'i' || f.specifier == 'u')
		count = ft_print_d_i_u(f, ap);
	if (f.specifier == 'X' || f.specifier == 'x')
		count = ft_print_x(f, ap);
	if (f.specifier == 'p')
		count = ft_print_p(f, ap);
	return (count);
}
