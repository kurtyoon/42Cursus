/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:06:09 by cyun              #+#    #+#             */
/*   Updated: 2023/01/19 00:33:16 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_just3(t_deque *a)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = a->top->data;
	n2 = a->top->next->data;
	n3 = a->bottom->data;
	if (n1 > n2 && n2 < n3 && n1 < n3)
		deque_swap_ab(a);
	if (n1 > n2 && n2 > n3 && n1 > n3)
	{
		deque_swap_ab(a);
		deque_rrotate_ab(a);
	}
	if (n1 > n2 && n2 < n3 && n1 > n3)
		deque_rotate_ab(a);
	if (n1 < n2 && n2 > n3 && n1 < n3)
	{
		deque_swap_ab(a);
		deque_rotate_ab(a);
	}
	if (n1 < n2 && n2 > n3 && n1 > n3)
		deque_rrotate_ab(a);
}

void	divide_3part(t_deque *a, t_deque *b, int pivot1, int pivot2)
{
	int	cnt;

	if (a->size > 10)
	{
		pivot1 = a->size / 3 * 1;
		pivot2 = a->size / 3 * 2;
		cnt = a->size;
		while (cnt && a->size > 3)
		{
			if (a->top->data <= pivot1)
			{
				deque_push_ab(b, a);
				deque_rotate_ab(b);
			}
			else if (a->top->data <= pivot2)
				deque_push_ab(b, a);
			else
				deque_rotate_ab(a);
			cnt--;
		}
	}
	while (a->size > 3)
		deque_push_ab(b, a);
	if (a->size == 3)
		sort_just3(a);
}

void	parse_argument(t_deque *a, t_deque *b, int argc, char **argv)
{
	if (argc == 1)
		exit(0);
	init_deque(a, b);
	receive_input(a, argc, argv);
	change_to_idx(a);
	if (deque_is_sorted(a, b))
		exit(0);
}

void	greedy(t_deque *a, t_deque *b)
{
	int	dest;
	int	sttp;

	while (b->size)
	{
		get_location(a, b, &dest, &sttp);
		greedy_rotate(a, b, dest, sttp);
		deque_push_ab(a, b);
	}
	last_rotate(a);
}

int	main(int argc, char **argv)
{
	t_deque	a;
	t_deque	b;

	parse_argument(&a, &b, argc, argv);
	divide_3part(&a, &b, a.size / 3 * 1, a.size / 3 * 2);
	greedy(&a, &b);
}
