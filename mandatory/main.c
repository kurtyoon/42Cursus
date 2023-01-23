/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:06:09 by cyun              #+#    #+#             */
/*   Updated: 2023/01/23 21:55:49 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// 요소가 3개일 때 경우의 수를 정해줌
void	sort_three_pivot(t_deque *a)
{
	int	top;
	int	mid;
	int	bottom;

	top = a->top->data;
	mid = a->top->next->data;
	bottom = a->bottom->data;
	if (top > mid && mid < bottom && top < bottom)
		deque_swap_ab(a);
	if (top > mid && mid > bottom && top > bottom)
	{
		deque_swap_ab(a);
		deque_rrotate_ab(a);
	}
	if (top > mid && mid < bottom && top > bottom)
		deque_rotate_ab(a);
	if (top < mid && mid > bottom && top < bottom)
	{
		deque_swap_ab(a);
		deque_rotate_ab(a);
	}
	if (top < mid && mid > bottom && top > bottom)
		deque_rrotate_ab(a);
}

void	divide_three_pivot(t_deque *a, t_deque *b, int pivot1, int pivot2)
{
	int	cnt;

	if (a->size > 10)
	{
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
	while (a->size > 3) // 덱 a에 3개의 요소만 남을 때 까지 push b
		deque_push_ab(b, a);
	if (a->size == 3) // 덱 a에 3개의 요소만 남았을 경우 정해진 알고리즘으로 정렬
		sort_three_pivot(a);
}

void	parse_argument(t_deque *a, t_deque *b, int argc, char **argv)
{
	if (argc == 1) // 인자가 1개라면 종료
		exit(0);
	init_deque(a, b); // 덱 구조체 초기화
	receive_input(a, argc, argv); // 덱에 인자 입력
	deque_is_duplicated(a); // 덱 중복 체크
	if (deque_is_sorted(a, b)) // 덱 정렬여부 체크
		exit(0);
}

void	greedy(t_deque *a, t_deque *b)
{
	int	move_a;
	int	move_b;

	while (b->size)
	{
		get_location(a, b, &move_a, &move_b);
		greedy_rotate(a, b, move_a, move_b);
		deque_push_ab(a, b);
	}
	last_rotate(a);
}

int	main(int argc, char **argv)
{
	t_deque	a;
	t_deque	b;

	parse_argument(&a, &b, argc, argv); // parsing
	divide_three_pivot(&a, &b, a.size / 3 * 1, a.size / 3 * 2); // 세 부분으로 나누기
	greedy(&a, &b);
	free_node(&a);
	free_node(&b);
}
