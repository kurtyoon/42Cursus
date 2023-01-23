/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 00:20:14 by cyun              #+#    #+#             */
/*   Updated: 2023/01/22 11:15:00 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	deque_swap_ab(t_deque *deque)
{
	t_node	*first;
	t_node	*second;

	first = deque_pop_top(deque);
	second = deque_pop_top(deque);
	deque_add_top(deque, first);
	deque_add_top(deque, second);
	ft_printf("s%c\n", deque->name);
}

void	deque_push_ab(t_deque *dest, t_deque *src)
{
	t_node	*tmp;

	tmp = deque_pop_top(src);
	if (tmp == NULL)
		return ;
	deque_add_top(dest, tmp);
	ft_printf("p%c\n", dest->name);
}

void	deque_rotate_ab(t_deque *deque)
{
	t_node	*tmp;

	tmp = deque_pop_top(deque);
	if (tmp == NULL)
	{
		ft_printf("Empty deque\n");
		exit(0);
	}
	deque_add_bottom(deque, tmp);
	ft_printf("r%c\n", deque->name);
}

void	deque_rrotate_ab(t_deque *deque)
{
	t_node	*tmp;

	tmp = deque_pop_bottom(deque);
	if (tmp == NULL)
	{
		ft_printf("Empty deque\n");
		exit(0);
	}
	deque_add_top(deque, tmp);
	ft_printf("rr%c\n", deque->name);
}
