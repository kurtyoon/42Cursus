/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbrs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 01:24:50 by cyun              #+#    #+#             */
/*   Updated: 2022/08/05 01:44:17 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	operation(t_format f)
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
		return (NULL);
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
	str = NULL;
	str = ft_allocate(str, len, n);
	if (!str)
		return (NULL);
	return (str);
}

int	ft_print_nbr(t_format f, char *nbr, int len, int neg)
{
	int	c;

	c = 0;
	f.width -= (f.space && !neg && !f.plus && f.width);
	if (neg || f.plus)
		c += ft_printnchar(operation(f), f.zero && (!f.dot || f.neg_prec));
	else if (f.space)
		c += ft_printnchar(' ', f.zero && !f.dot);
	if (!f.minus && f.width > f.precision && (!f.dot || f.neg_prec) && f.zero)
		c += ft_printnchar('0', f.width - f.precision - neg - f.plus);
	else if (!f.minus && f.width > f.precision)
		c += ft_printnchar(' ', f.width - f.precision - neg - f.plus);
	if (neg || f.plus)
		c += ft_printnchar(operation(f), !f.zero || (f.dot && !f.neg_prec));
	else if (f.space)
		c += ft_printnchar(' ', !f.zero || f.dot);
	c += ft_printnchar('0', f.precision - len);
	c += write(1, nbr, len);
	if (f.minus && f.width > f.precision)
		c += ft_printnchar(' ', f.width - f.precision - neg - f.plus);
	return (c);
}

int	ft_print_d_i_u(t_format f, va_list ap)
{
	char	*nbr;
	int		n;
	int		c;
	int		len;
	int		neg;

	c = 0;
	n = va_arg(ap, int);
	neg = (n < 0 && n != INT_MIN && f.specifier != 'u');
	if (neg)
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
	c += ft_print_nbr(f, nbr, len, neg);
	free(nbr);
	return (c);
}
