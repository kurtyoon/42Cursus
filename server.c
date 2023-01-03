/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:07:20 by cyun              #+#    #+#             */
/*   Updated: 2023/01/03 10:38:17 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handler(int signal)
{
	static int	bit; // 비트를 얼마나 받았는 지 확인하는 정적 변수
	static char	tmp; // 비트를 저장하는 정적 변수
	
	if (signal == SIGUSR1) // SIGUSR2 일 때는 어차피 0 이므로 pass 가능
		tmp |= (1 << bit); // 가장 오른쪽 비트부터 받아옴
	bit++;
	if (bit == 8) // 비트가 8이 될 경우 저장된 문자를 출력하고 정적변수 초기화
	{
		ft_putchar_fd(tmp, 1);
		bit = 0;
		tmp = 0;
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
	// signal(SIGUSR1, ft_handler);
	// signal(SIGUSR2, ft_handler);
	while (argc == 1)
	{
		signal(SIGUSR1, ft_handler);
		signal(SIGUSR2, ft_handler);
		pause(); // 요청이 들어올 때 까지 대기
	}
	return (0);
}
