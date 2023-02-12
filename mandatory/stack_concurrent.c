/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_concurrent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 21:58:23 by cyun              #+#    #+#             */
/*   Updated: 2023/02/12 12:47:53 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	stack_swap_ss(t_stacks *a, t_stacks *b)
{
	int	tmp;
	if (a->top >= 1)
	{
		tmp = a->stack[a->top];
		a->stack[a->top] = a->stack[a->top - 1];
		a->stack[a->top - 1] = tmp;
	}
	if (b->top >= 1)
	{
		tmp = b->stack[b->top];
		b->stack[b->top] = b->stack[b->top - 1];
		b->stack[b->top - 1] = tmp;
	}
    ft_printf("ss\n");
}

void	stack_rotate_rr(t_stacks *a, t_stacks *b)
{
	int	tmp;
	int	idx;

	idx = a->top;
	if (idx != -1)
	{
		tmp = a->stack[a->top];
		while (idx > 0)
		{
			a->stack[idx] = a->stack[idx - 1];
			idx--;
		}
		a->stack[0] = tmp;
	}
	idx = b->top;
	if (idx != -1)
	{
		tmp = b->stack[b->top];
		while (idx > 0)
		{
			b->stack[idx] = b->stack[idx - 1];
			idx--;
		}
		b->stack[0] = tmp;
	}
    ft_printf("rr\n");
}

void	stack_rrotate_rrr(t_stacks *a, t_stacks *b)
{
	int	tmp;
	int	idx;

	idx = 0;
	tmp = a->stack[0];
	while (idx < a->top)
	{
		a->stack[idx] = a->stack[idx + 1];
		idx++;
	}
	a->stack[a->top] = tmp;
	idx = 0;
	tmp = b->stack[0];
	while (idx < b->top)
	{
		b->stack[idx] = b->stack[idx + 1];
		idx++;
	}
	b->stack[b->top] = tmp;
    ft_printf("rrr\n", 4);
}
