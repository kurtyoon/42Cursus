/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:07:20 by cyun              #+#    #+#             */
/*   Updated: 2022/12/27 16:17:00 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handler(int signal)
{
	static int	bit;
	static int	i;

	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_putchar_fd((char)i, 1);
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc != 1) // 인자가 1개일 경우 에러처리
	{
		ft_putstr_fd("Error: worng format.\n", 1);
		ft_putstr_fd("Try: ./server\n", 1);
		return (0);
	}
	pid = getpid(); // pid를 생성
	ft_putstr_fd("PID -> ", 1);
	ft_putnbr_fd(pid, 1); // pid 출력
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("Waiting for a message...\n", 1);
	while (argc == 1)
	{
		signal(SIGUSR1, ft_handler);
		signal(SIGUSR2, ft_handler);
		pause();
	}
	return (0);
}
