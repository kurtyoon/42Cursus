/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:51:32 by cyun              #+#    #+#             */
/*   Updated: 2023/01/21 20:11:22 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

// 덱 구조체 초기화 함수
void	init_deque(t_deque *a, t_deque *b)
{
	a->top = NULL;
	a->bottom = NULL;
	b->top = NULL;
	b->bottom = NULL;
	a->size = 0;
	b->size = 0;
	a->name = 'a';
	b->name = 'b';
}

void	parse_argument(t_deque *a, t_deque *b, int argc, char **argv)
{
	if (argc == 1)
		exit(0);
	init_deque(a, b);
	receive_input(a, argc, argv);
	change_to_idx(a);
}

int	check_sorted(t_deque *a, t_deque *b)
{
	int		i;
	t_node	*p;

	if (b->size)
		return (0);
	p = a->top;
	i = 0;
	while (i < a->size - 1)
	{
		if (p->data > p->next->data)
			return (0);
		i++;
		p = p->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_deque		a;
	t_deque		b;
	char		**commands;

	parse_argument(&a, &b, argc, argv);
	commands = read_commands();
	execute_commands(&a, &b, commands);
	if (check_sorted(&a, &b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (0);
}
