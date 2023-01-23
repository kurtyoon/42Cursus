/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_concurrent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 00:34:10 by cyun              #+#    #+#             */
/*   Updated: 2023/01/22 11:14:49 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	deque_swap_ss(t_deque *x, t_deque *y)
{
	t_node	*p;
	t_node	*q;

	p = deque_pop_top(x);
	q = deque_pop_top(x);
	deque_add_top(x, p);
	deque_add_top(x, q);
	p = deque_pop_top(y);
	q = deque_pop_top(y);
	deque_add_top(y, p);
	deque_add_top(y, q);
	ft_printf("ss\n");
}

void	deque_rotate_rr(t_deque *x, t_deque *y)
{
	t_node	*p;

	p = deque_pop_top(x);
	if (p == NULL)
	{
		ft_printf("Empty deque\n");
		exit(0);
	}
	deque_add_bottom(x, p);
	p = deque_pop_top(y);
	if (p == NULL)
	{
		ft_printf("Empty deque\n");
		exit(0);
	}
	deque_add_bottom(y, p);
	ft_printf("rr\n");
}

void	deque_rrotate_rrr(t_deque *x, t_deque *y)
{
	t_node	*p;

	p = deque_pop_bottom(x);
	if (p == NULL)
	{
		ft_printf("Empty deque\n");
		exit(0);
	}
	deque_add_top(x, p);
	p = deque_pop_bottom(y);
	if (p == NULL)
	{
		ft_printf("Empty deque\n");
		exit(0);
	}
	deque_add_top(y, p);
	ft_printf("rrr\n");
}
