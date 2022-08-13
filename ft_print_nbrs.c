/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbrs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 21:30:20 by cyun              #+#    #+#             */
/*   Updated: 2022/08/10 23:46:29 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	oper(t_format f)
{
	if (f.plus)
		return ('+');
	return ('-');
}

char	*ft_allocate(char *str, int len, unsigned int n)
{
	if (n == 0)
		len = 1;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len] = '\0';
	while (len-- > 0)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

char	*ft_uitoa(unsigned int n)
{
	char	*str;
	int		len;

	len = ft_nbrlen(n, 10);
	str = 0;
	str = ft_allocate(str, len, n);
	if (!str)
		return (0);
	return (str);
}

int	ft_print_nbr(t_format f, char *nbr, int len, int n)
{
	int	print_len;

	print_len = 0;
	f.width -= (f.space && !f.neg && !f.plus && f.width);
	if ((f.neg || f.plus) && n != INT_MIN)
		print_len += ft_printnchar(oper(f), f.zero && (!f.dot || f.neg_prec));
	else if (f.space && n != INT_MIN)
		print_len += ft_printnchar(' ', f.zero && !f.dot);
	if (!f.minus && f.width > f.precision && (!f.dot || f.neg_prec) && f.zero)
		print_len += ft_printnchar('0', f.width - f.precision - f.neg - f.plus);
	else if (!f.minus && f.width > f.precision)
		print_len += ft_printnchar(' ', f.width - f.precision - f.neg - f.plus);
	if ((f.neg || f.plus) && n != INT_MIN)
		print_len += ft_printnchar(oper(f), !f.zero || (f.dot && !f.neg_prec));
	else if (f.space && n != INT_MIN)
		print_len += ft_printnchar(' ', !f.zero || f.dot);
	print_len += ft_printnchar('0', f.precision - len);
	print_len += write(1, nbr, len);
	if (f.minus && f.width > f.precision)
		print_len += ft_printnchar(' ', f.width - f.precision - f.neg - f.plus);
	return (print_len);
}

int	ft_print_d_i_u(t_format f, va_list ap)
{
	char	*nbr;
	int		n;
	int		print_len;
	int		len;

	print_len = 0;
	n = va_arg(ap, int);
	f.neg = (n < 0 && n != INT_MIN && f.specifier != 'u');
	if (f.neg)
		f.plus = 0;
	if (n < 0 && f.specifier != 'u')
		n *= -1;
	if (n < 0 && f.specifier == 'u')
		nbr = ft_uitoa((unsigned)n);
	else
		nbr = ft_itoa(n);
	len = ft_strlen(nbr);
	if (*nbr == '0' && !f.precision && f.dot)
		len = 0;
	if (f.precision < len || !f.dot)
		f.precision = len;
	print_len += ft_print_nbr(f, nbr, len, n);
	free(nbr);
	return (print_len);
}
