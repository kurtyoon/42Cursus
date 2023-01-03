/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:16:23 by cyun              #+#    #+#             */
/*   Updated: 2023/01/04 01:51:01 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	ft_handler(int signal, siginfo_t *info, void *s)
{
	static int	bit; // 비트를 얼마나 받았는지 확인하는 정적 변수
	static char	tmp; // 비트를 저장하는 정적 변수
	pid_t		pid;

	(void)s;
	pid = info->si_pid;
	if (signal == SIGUSR1)
		tmp |= (1 << bit);
	bit++;
	if (bit == 8) // 비트가 8이 될 경우 저장된 문자를 출력하고 정적변수 초기화
	{
		if (tmp != '\0')
			ft_putchar_fd(tmp, 1);
		else
			kill(pid, SIGUSR1); // 이거면 메시지가 전부 보내짐
		bit = 0;
		tmp = 0;
	}
}

static void ft_pid_print(pid_t pid)
{
	ft_putstr_fd("PID -> ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("Waiting for a message...\n", 1);
}

int	main(int argc, char **argv)
{
	struct sigaction	sig;
	pid_t				pid;

	(void)argv;
	if (argc != 1) // 인자가 잘못될 경우
	{
		ft_putstr_fd("Error: worng format.\n", 1);
		ft_putstr_fd("Try: ./server\n", 1);
		return (0);
	}
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = &ft_handler; // sigaction 연결
	sigemptyset(&sig.sa_mask);
	pid = getpid(); // pid 생성
	ft_pid_print(pid);
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
	return (0);
}
