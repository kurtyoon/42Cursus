/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 00:41:03 by cyun              #+#    #+#             */
/*   Updated: 2022/08/05 01:45:58 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

# define INT_MIN -2147483648
# define UINT_MAX 4294967895
# define SPECIFIERS "cspdiuxX%"
# define HEXLOW "0123456789abcdef"
# define HEXUP "0123456789ABCDEF"

typedef struct s_format
{
	int		minus;
	int		plus;
	int		width;
	int		precision;
	int		neg_prec;
	int		zero;
	int		dot;
	int		space;
	int		sharp;
	char	specifier;
}t_format;

int			ft_nbrlen(long n, int base);
int			ft_printstrn(char *str, int n);
int			ft_printnchar(int c, int n);
int			ft_printchar(int c);
int			ft_printf(const char *str, ...);
t_format	ft_newformat(void);
int			ft_print_format(t_format f, va_list ap);
int			ft_print_c_pct(t_format f, va_list ap);
int			ft_print_s(t_format f, va_list ap);
int			ft_print_d_i_u(t_format f, va_list ap);
int			ft_print_x(t_format f, va_list ap);
int			ft_print_p(t_format f, va_list ap);
int			ft_parse(char *str, va_list ap);

#endif