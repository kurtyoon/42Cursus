/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 21:57:10 by cyun              #+#    #+#             */
/*   Updated: 2023/02/12 18:56:30 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	stack_swap_ab(t_stack *stack)
{
	int	tmp;

	if (stack->top >= 1)
	{
		tmp = stack->stack[stack->top];
		stack->stack[stack->top] = stack->stack[stack->top - 1];
		stack->stack[stack->top - 1] = tmp;
	}
}

void	stack_push_ab(t_stack *from, t_stack *to)
{
	if (from->top >= 0)
	{
		to->top += 1;
		to->stack[to->top] = from->stack[from->top];
		from->top -= 1;
	}
}

void	stack_rotate_ab(t_stack *stack)
{
	int	tmp;
	int	idx;

	idx = stack->top;
	if (idx != -1)
	{
		tmp = stack->stack[stack->top];
		while (idx > 0)
		{
			stack->stack[idx] = stack->stack[idx - 1];
			idx--;
		}
		stack->stack[0] = tmp;
	}
}

void	stack_rrotate_ab(t_stack *stack)
{
	int	tmp;
	int	idx;

	idx = 0;
	tmp = stack->stack[0];
	while (idx < stack->top)
	{
		stack->stack[idx] = stack->stack[idx + 1];
		idx++;
	}
	stack->stack[stack->top] = tmp;
}
