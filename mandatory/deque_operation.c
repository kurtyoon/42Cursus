/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 00:20:14 by cyun              #+#    #+#             */
/*   Updated: 2023/01/14 16:17:31 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	deque_swap_ab(t_deque *x)
{
	t_node	*p;
	t_node	*q;

	p = deque_pop_top(x);
	q = deque_pop_top(x);
	deque_add_top(x, p);
	deque_add_top(x, q);
	ft_printf("s%c\n", x->name);
}

void	deque_push_ab(t_deque *x, t_deque *y)
{
	t_node	*p;

	p = deque_pop_top(y);
	if (p == NULL)
		return ;
	deque_add_top(x, p);
	ft_printf("p%c\n", x->name);
}

void	deque_rotate_ab(t_deque *x)
{
	t_node	*p;

	p = deque_pop_top(x);
	if (p == NULL)
	{
		ft_printf("Empty deque\n");
		exit(0);
	}
	deque_add_bottom(x, p);
	ft_printf("r%c\n", x->name);
}

void	deque_rrotate_ab(t_deque *x)
{
	t_node	*p;

	p = deque_pop_bottom(x);
	if (p == NULL)
	{
		ft_printf("Empty deque\n");
		exit(0);
	}
	deque_add_top(x, p);
	ft_printf("rr%c\n", x->name);
}