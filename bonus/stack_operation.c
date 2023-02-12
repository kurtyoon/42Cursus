/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 21:57:10 by cyun              #+#    #+#             */
/*   Updated: 2023/02/12 13:08:21 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	stack_swap_ab(t_stacks *stack)
{
	int	tmp;
	if (stack->top >= 1)
	{
		tmp = stack->stack[stack->top];
		stack->stack[stack->top] = stack->stack[stack->top - 1];
		stack->stack[stack->top - 1] = tmp;
	}
	ft_printf("s%c\n", stack->name);
}

void	stack_push_ab(t_stacks *from, t_stacks *to)
{
	if (from->top >= 0)
	{
		to->top += 1;
		to->stack[to->top] = from->stack[from->top];
		from->top -= 1;
		ft_printf("p%c\n", to->name);
	}
}

void	stack_rotate_ab(t_stacks *stack)
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
	ft_printf("r%c\n", stack->name);
}

void	stack_rrotate_ab(t_stacks *stack)
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
	ft_printf("rr%c\n", stack->name);
}
