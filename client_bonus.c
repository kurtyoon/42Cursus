/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:13:19 by cyun              #+#    #+#             */
/*   Updated: 2022/12/27 16:55:48 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	ft_confirm(int signal)
{
	if (signal == SIGUSR1)
		ft_putstr_fd(".", 1);
	else
		ft_putstr_fd(".", 1);
}

void	ft_send_bits(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1); // bit값이 1일 경우에 SIGUSR1신호를 보냄
		else
			kill(pid, SIGUSR2); // bit값이 0일 경우에 SIGUSR2신호를 보냄
		usleep(100);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			signal(SIGUSR1, ft_confirm);
			signal(SIGUSR2, ft_confirm);
			ft_send_bits(pid, argv[2][i]);
			i++;
		}
		ft_send_bits(pid, '\n');
		ft_putstr_fd("Complete\n", 1);
	}
	else
	{
		ft_putstr_fd("Error: wrong format.\n", 1);
		ft_putstr_fd("Try: ./client_bonus [PID] [MESSAGE]\n", 1);
		return (1);
	}
	return (0);
}
