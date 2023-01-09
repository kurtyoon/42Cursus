/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:27:24 by cyun              #+#    #+#             */
/*   Updated: 2023/01/09 16:11:27 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
		write(fd, &s[i++], 1);
}

void	rec_putnbr(int nb, int fd)
{
	char	c;

	if (nb == 0)
		return ;
	c = '0' + nb % 10;
	rec_putnbr(nb / 10, fd);
	ft_putchar_fd(c, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n < 0)
	{
		write(fd, "-", 1);
		c = '0' - n % 10;
		rec_putnbr(-(n / 10), fd);
	}
	else
	{
		c = '0' + n % 10;
		rec_putnbr(n / 10, fd);
	}
	ft_putchar_fd(c, fd);
}

int	count_nbr(long long n)
{
	int	cnt_nbr;

	if (n == 0 || n == -0)
		return (1);
	cnt_nbr = 0;
	if (n < 0)
		cnt_nbr = 1;
	while (n)
	{
		n /= 10;
		cnt_nbr++;
	}
	return (cnt_nbr);
}

char	*ft_itoa(int n)
{
	long long	nbr;
	char		*res;
	int			len;

	len = count_nbr(n);
	nbr = (long long)n;
	if (n < 0)
		nbr *= -1;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len--] = '\0';
	while (len >= 0)
	{
		res[len] = nbr % 10 + '0';
		nbr /= 10;
		len--;
	}
	if (n < 0)
		res[0] = '-';
	return (res);
}
