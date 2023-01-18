/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 00:20:14 by cyun              #+#    #+#             */
/*   Updated: 2023/01/19 00:36:04 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	deque_swap_ab(t_deque *x)
{
	t_node	*p;
	t_node	*q;

	p = deque_pop_top(x);
	q = deque_pop_top(x);
	deque_add_top(x, p);
	deque_add_top(x, q);
}

void	deque_push_ab(t_deque *x, t_deque *y)
{
	t_node	*p;

	p = deque_pop_top(y);
	if (p == NULL)
		return ;
	deque_add_top(x, p);
}

void	deque_rotate_ab(t_deque *x)
{
	t_node	*p;

	p = deque_pop_top(x);
	if (p == NULL)
		exit(0);
	deque_add_bottom(x, p);
}

void	deque_rrotate_ab(t_deque *x)
{
	t_node	*p;

	p = deque_pop_bottom(x);
	if (p == NULL)
		exit(0);
	deque_add_top(x, p);
}
