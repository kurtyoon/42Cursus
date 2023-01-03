/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:13:19 by cyun              #+#    #+#             */
/*   Updated: 2023/01/02 16:18:00 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_confirm(int signal)
{
	// if (signal == SIGUSR1)
	// 	ft_putstr_fd(".", 1);
	// else
	// 	ft_putstr_fd(".", 1);
	ft_putstr_fd("Complete..\n", 1);
	exit(0);
}

void	ft_send_bits(int pid, char input)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((input & (1 << bit)) != 0)
			kill(pid, SIGUSR1); // bit값이 1일 경우에 SIGUSR1신호를 보냄
		else
			kill(pid, SIGUSR2); // bit값이 0일 경우에 SIGUSR2신호를 보냄
		usleep(100);
		bit++;
	}
}

void	ft_send_str(int pid, char input[])
{
	int	i;

	i = 0;
	while (input[i] != '\0')
	{
		ft_send_bits(pid, input[i]);
		i++;
	}
	ft_send_bits(pid, '\n');
}

int	main(int argc, char **argv)
{
	int	pid;
	// int	i;

	// i = 0;
	if (argc == 3) // 인자가 유효할 경우
	{
		signal(SIGUSR1, ft_confirm);
		pid = ft_atoi(argv[1]); // pid를 인자에서 가져옴
		if (pid <= 100 || pid >= 99999) // 100이하는 시스템pid, 99999이상은 존재하지 않음
		{
			ft_putstr_fd("Error: wrong pid.\n", 1);
			return (0);
		}
		// while (argv[2][i] != '\0')
		// {
		// 	signal(SIGUSR1, ft_confirm);
		// 	signal(SIGUSR2, ft_confirm);
		// 	ft_send_bits(pid, argv[2][i]); // 한 글자씩 전송
		// 	i++;
		// }
		// ft_send_bits(pid, '\n'); // 개행문자 전송
		ft_send_str(pid, argv[2]);
		// signal(SIGUSR1, ft_confirm);
		// signal(SIGUSR2, ft_confirm);
		while (1)
			pause();
	}
	else // 인자가 유효하지 않을 경우
	{
		ft_putstr_fd("Error: wrong format.\n", 1);
		ft_putstr_fd("Try: ./client [PID] [MESSAGE]\n", 1);
	}
	return (0);
}
