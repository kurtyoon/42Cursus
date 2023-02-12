/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 22:11:33 by cyun              #+#    #+#             */
/*   Updated: 2023/02/12 19:57:50 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	set_min_rotate(t_stack *a, t_stack *b, int *move_a, int *move_b)
{
	int	i;
	int	b_size;
	int	b_idx;
	int	pos_a;
	int	pos_b;

	i = 0;
	b_size = b->top + 1;
	b_idx = b->top;
	while (i < b_size)
	{
		pos_a = get_a_position(a, b->stack[b_idx]);
		pos_b = i;
		if (pos_b > (b->top + 1) / 2)
			pos_b = i - (b->top + 1);
		if (i == 0 || compare_cnt(pos_a, pos_b, *move_a, *move_b))
		{
			*move_a = pos_a;
			*move_b = pos_b;
		}
		b_idx--;
		i++;
	}
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

void	greedy_rotate(t_stack *a, t_stack *b, int move_a, int move_b)
{
	if (move_a == move_b)
	{
		while (move_a > 0)
		{
			stack_rotate_rr(a, b);
			move_a--;
		}
		while (move_a++ < 0)
			stack_rrotate_rrr(a, b);
		return ;
	}
	while (move_a > 0)
	{
		stack_rotate_ab(a, 1);
		move_a--;
	}
	while (move_a++ < 0)
		stack_rrotate_ab(a, 1);
	while (move_b > 0)
	{
		stack_rotate_ab(b, 1);
		move_b--;
	}
	while (move_b++ < 0)
		stack_rrotate_ab(b, 1);
}

void	last_rotate(t_stack *a)
{
	int	pos_min;
	int	idx;

	pos_min = 0;
	idx = a->top;
	while (pos_min < a->top)
	{
		if (a->stack[idx] > a->stack[idx - 1])
			break ;
		pos_min++;
		idx--;
	}
	if (pos_min >= a->top / 2)
	{
		while (a->stack[0] < a->stack[a->top])
			stack_rrotate_ab(a, 1);
	}
	else
	{
		while (a->stack[0] < a->stack[a->top])
			stack_rotate_ab(a, 1);
	}
}

int	get_a_position(t_stack *a, int num)
{
	int	cur;
	int	pos_a;
	int	prev;

	cur = a->top;
	pos_a = 0;
	while (cur >= 0)
	{
		prev = cur + 1;
		if (pos_a == 0)
			prev = 0;
		if (a->stack[prev] > num && \
			a->stack[cur] > num && a->stack[prev] > a->stack[cur])
			break ;
		if (a->stack[prev] < num && \
			a->stack[cur] > num && a->stack[prev] < a->stack[cur])
			break ;
		if (a->stack[prev] < num && \
			a->stack[cur] < num && a->stack[prev] > a->stack[cur])
			break ;
		pos_a++;
		cur--;
	}
	if (pos_a > (a->top + 1) / 2)
		pos_a = pos_a - (a->top + 1);
	return (pos_a);
}
 