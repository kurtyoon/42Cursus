/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 01:33:29 by cyun              #+#    #+#             */
/*   Updated: 2022/08/05 01:42:58 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_sharp(t_format f)
{
	if (f.specifier == 'X')
		return ("0X");
	return ("0x");
}

int	ft_nbrlen(long n, int base)
{
	int	len;

	len = 0;
	if (!base)
		base = 10;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		len++;
		n /= base;
	}
	return (len);
}

int	ft_recursive_hex(t_format f, size_t n, size_t iteration)
{
	int		count;
	int		remainder;
	char	character;

	count = 0;
	if (n > 0 || (!iteration && (f.specifier != 'p' || !f.dot)))
	{
		remainder = n % 16;
		if (f.specifier != 'X')
			character = HEXLOW[remainder];
		else
			character = HEXUP[remainder];
		n /= 16;
		iteration = 1;
		count += ft_recursive_hex(f, n, iteration);
		count += ft_printchar(character);
	}
	return (count);
}

int	ft_print_x(t_format f, va_list ap)
{
	int				count;
	unsigned int	n;
	int				len;

	count = 0;
	n = va_arg(ap, unsigned int);
	len = ft_nbrlen(n, 16);
	if (!n && !f.precision && f.dot)
		len = 0;
	if (f.precision < 0 || f.precision < len || !f.dot)
		f.precision = len;
	if (f.sharp && n)
		f.width -= 2;
	count += ft_printstrn(ft_sharp(f), 2 * (f.sharp && f.zero && n));
	if (!f.minus && f.width > f.precision && (!f.dot || f.neg_prec) && f.zero)
		count += ft_printnchar('0', (f.width - f.precision));
	else if (!f.minus && f.width > f.precision)
		count += ft_printnchar(' ', (f.width - f.precision));
	count += ft_printstrn(ft_sharp(f), 2 * (f.sharp && !f.zero && n));
	count += ft_printnchar('0', (f.precision - len));
	if (len)
		count += ft_recursive_hex(f, n, n);
	if (f.minus && f.width > f.precision)
		count += ft_printnchar(' ', f.width - f.precision);
	return (count);
}

int	ft_print_p(t_format f, va_list ap)
{
	int		count;
	size_t	n;
	int		len;

	count = 0;
	n = va_arg(ap, size_t);
	len = ft_nbrlen(n, 16);
	len *= !(!n && !f.precision && f.dot);
	if (f.precision < len || !f.dot)
		f.precision = len;
	count += write(1, "0x", 2 * f.zero);
	f.width -= 2;
	if (!f.minus && f.width > f.precision && !f.dot && f.zero)
		count += ft_printnchar('0', (f.width - f.precision));
	else if (!f.minus && f.width > f.precision)
		count += ft_printnchar(' ', (f.width - f.precision));
	count += write(1, "0x", 2 * !f.zero);
	count += ft_printnchar('0', (f.precision - len) * (n != 0));
	count += ft_printnchar('0', f.precision * (f.dot && !n));
	if (len)
		count += ft_recursive_hex(f, n, n);
	if (f.minus && f.width > f.precision)
		count += ft_printnchar(' ', f.width - f.precision);
	return (count);
}
