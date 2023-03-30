/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:15:12 by cyun              #+#    #+#             */
/*   Updated: 2023/01/14 15:54:56 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

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
