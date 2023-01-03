/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:04:36 by cyun              #+#    #+#             */
/*   Updated: 2023/01/03 10:37:50 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_bits(int pid, char input)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		// 가장 오른쪽 비트부터 왼쪽으로 가면서 전송함
		if ((input & (1 << bit)) != 0) // 1을 bit만큼 left shift연산 한 값을 c와 &연산
			kill(pid, SIGUSR1); // bit값이 1일 경우에 SIGUSR1 신호를 보냄
		else
			kill(pid, SIGUSR2); // bit값이 0일 경우에 SIGUSR2 신호를 보냄
		usleep(100);
		bit++;
	}
}

void	ft_send_str(int pid, char input[])
{
	int	i;

	i = 0;
	while (input[i] != '\0') // 한 문자씩 전송함
	{
		ft_send_bits(pid, input[i]);
		i++;
	}
	ft_send_bits(pid, '\n');
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3) // 인자가 정확할 경우
	{
		pid = ft_atoi(argv[1]); // 입력된 pid 받아오기
		if (pid <= 100 || pid >= 99999) // pid의 범위 처리. 100이하는 시스템, 99999이상은 없는 pid
		{
			ft_putstr_fd("Error: wrong pid.\n", 1);
			return (0);
		}
		// while (argv[2][i] != '\0')
		// {
		// 	ft_send_bits(pid, argv[2][i]); // 한 글자씩 전달
		// 	i++;
		// }
		// ft_send_bits(pid, '\n'); // 개행문자 전달
		ft_send_str(pid, argv[2]); // 문자열을 한번에 전달
	}
	else // 인자가 유효하지 않은 경우
	{
		ft_putstr_fd("Error: wrong format.\n", 1);
		ft_putstr_fd("Try: ./client [PID] [MESSAGE]\n", 1);
	}
	return (0);
}
