/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 01:17:44 by cyun              #+#    #+#             */
/*   Updated: 2022/08/05 01:43:01 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printnchar(int c, int n)
{
	int	count;

	count = 0;
	while (n-- > 0)
		count += (int)write(1, &c, 1);
	return (count);
}

int	ft_printstrn(char *str, int n)
{
	if (str != NULL)
		return ((int)write(1, str, n));
	return (0);
}

int	ft_print_c_pct(t_format f, va_list ap)
{
	char	c;
	int		count;

	count = 0;
	if (f.specifier == 'c')
		c = va_arg(ap, int);
	else
		c = '%';
	f.precision = 1;
	if (!f.minus && f.zero)
		count += ft_printnchar('0', f.width - f.precision);
	else if (!f.minus && f.width > f.precision)
		count += ft_printnchar(' ', f.width - f.precision);
	count += ft_printchar(c);
	if (f.minus && f.width - f.precision < 0)
		count += ft_printnchar(' ', f.width - f.precision);
	return (count);
}

int	ft_print_s(t_format f, va_list ap)
{
	char	*string;
	int		count;

	count = 0;
	string = va_arg(ap, char *);
	if (!string)
		string = "(null)";
	if (!f.dot || f.precision > (int)ft_strlen(string) || f.precision < 0)
		f.precision = ft_strlen(string);
	if (!f.minus && f.width > f.precision && f.zero && (!f.dot || f.neg_prec))
		count += ft_printnchar('0', f.width - f.precision);
	else if (!f.minus && f.width - f.precision > 0)
		count += ft_printnchar(' ', f.width - f.precision);
	count += ft_printstrn(string, f.precision);
	if (f.minus && f.width - f.precision > 0)
		count += ft_printnchar(' ', f.width - f.precision);
	return (count);
}
