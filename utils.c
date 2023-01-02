/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:39:57 by cyun              #+#    #+#             */
/*   Updated: 2023/01/02 11:27:26 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "minitalk_bonus.h"

// write character
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// write string
void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
		write(fd, &s[i++], 1);
}

// recursive func
void	rec_putnbr(int nb, int fd)
{
	char	c;

	if (nb == 0)
		return ;
	c = '0' + nb % 10;
	rec_putnbr(nb / 10, fd);
	ft_putchar_fd(c, fd);
}

// write number
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

// transform ascii to integer
int	ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	sign;

	i = 0;
	num = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0') * sign;
		i++;
	}
	return (num);
}
