/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 01:00:05 by cyun              #+#    #+#             */
/*   Updated: 2023/02/06 11:40:49 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_position(t_deque *a, t_node *src) // 몇 번 움직여야 하는지 찾아줌
{
	t_node	*p;
	int		move;

	p = a->top;
	move = 0;
	while (p)
	{
		if (p->prev->data > src->data && \
			p->data > src->data && p->prev->data > p->data)
			break ;
		if (p->prev->data < src->data && \
			p->data > src->data && p->prev->data < p->data)
			break ;
		if (p->prev->data < src->data && \
			p->data < src->data && p->prev->data > p->data)
			break ;
		p = p->next;
		move++;
	}
	if (move > a->size / 2) // 절반보다 큰 경우 최적화
		move = move - a->size;
	return (move);
}

int	compare_cnt(int pos_a, int pos_b, int move_a, int move_b)
{
	int	cnt;
	int	tmp_cnt;

	tmp_cnt = ft_abs(pos_a) + ft_abs(pos_b);
	cnt = ft_abs(move_a) + ft_abs(move_b);
	if (tmp_cnt < cnt)
		return (1);
	return (0);
}

void	get_location(t_deque *a, t_deque *b, int *move_a, int *move_b)
{
	int		i;
	int		pos_a;
	int		pos_b;
	t_node	*tmp;

	i = 0;
	tmp = b->top;
	while (i < b->size)
	{
		pos_a = get_position(a, tmp);
		pos_b = i; // b는 인덱스 만큼 움직여야 함
		if (pos_b > b->size / 2) // 절반보다 큰 경우 최적화
			pos_b = i - b->size;
		if (i == 0 || compare_cnt(pos_a, pos_b, *move_a, *move_b))
		{
			*move_a = pos_a;
			*move_b = pos_b;
		}
		tmp = tmp->next; // 덱 b 순회
		i++;
	}
}

// 정해진 그리디 알고리즘
void	greedy_rotate(t_deque *a, t_deque *b, int move_a, int move_b)
{
	if (move_a == move_b)
	{
		while (move_a > 0)
		{
			deque_rotate_rr(a, b);
			move_a--;
		}
		while (move_a++ < 0)
			deque_rrotate_rrr(a, b);
		return ;
	}
	while (move_a > 0)
	{
		deque_rotate_ab(a);
		move_a--;
	}
	while (move_a++ < 0)
		deque_rrotate_ab(a);
	while (move_b > 0)
	{
		deque_rotate_ab(b);
		move_b--;
	}
	while (move_b++ < 0)
		deque_rrotate_ab(b);
}

// 그래프 형식으로 정렬되어 있는 걸 일자로 변환
void	last_rotate(t_deque *a)
{
	int		turning_point;
	t_node	*tmp;

	turning_point = 1;
	tmp = a->top;
	while (turning_point < a->size)
	{
		if (tmp->data > tmp->next->data)
			break ;
		turning_point++;
		tmp = tmp->next;
	}
	if (turning_point >= a->size / 2)
	{
		while (a->bottom->data < a->top->data)
			deque_rrotate_ab(a);
	}
	else
	{
		while (a->bottom->data < a->top->data)
			deque_rotate_ab(a);
	}
}
