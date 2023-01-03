/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:16:23 by cyun              #+#    #+#             */
/*   Updated: 2023/01/03 16:04:00 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_handler(int signal, siginfo_t *info, void *s)
{
	static int	bit; // 비트를 얼마나 받았는지 확인하는 정적 변수
	static char	tmp; // 비트를 저장하는 정적 변수

	(void)s;
	if (signal == SIGUSR1)
		tmp |= (1 << bit);
	bit++;
	if (bit == 8) // 비트가 8이 될 경우 저장된 문자를 출력하고 정적변수 초기화
	{
		ft_putchar_fd(tmp, 1);
		bit = 0;
		tmp = 0;
		kill(info->si_pid, SIGUSR1);
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sig;

	(void)argv;
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = &ft_handler;
	sigemptyset(&sig.sa_mask);
	if (argc != 1) // 인자가 잘못될 경우
	{
		ft_putstr_fd("Error: worng format.\n", 1);
		ft_putstr_fd("Try: ./server\n", 1);
		return (0);
	}
	pid = getpid(); // pid 생성
	ft_putstr_fd("PID -> ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1); // pid 출력
	ft_putstr_fd("Waiting for a message...\n", 1);
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (argc == 1)
	{
		// sigaction(SIGUSR1, &sig, NULL);
		// sigaction(SIGUSR2, &sig, NULL);
		pause();
	}
	return (0);
}
