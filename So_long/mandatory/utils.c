/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:27:24 by cyun              #+#    #+#             */
/*   Updated: 2023/01/19 18:26:45 by cyun             ###   ########seoul.kr  */
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
