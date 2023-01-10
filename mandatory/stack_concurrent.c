/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_concurrent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:50:27 by cyun              #+#    #+#             */
/*   Updated: 2023/01/10 15:54:35 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// sa + sb
int	st_swap_ss(t_list **a, t_list **b)
{
	st_swap_ab(a, 0);
	st_swap_ab(b, 0);
	ft_putstr_fd("ss\n", 1);
	return (1);
}

// ra + rb
int	st_rotate_rr(t_list **a, t_list **b)
{
	if (!st_rotate_ab(a, 0))
		return (0);
	if (!st_rotate_ab(b, 0))
		return (0);
	ft_putstr_fd("rr\n", 1);
	return (1);
}

// rra + rrb
int	st_rrotate_rrr(t_list **a, t_list **b)
{
	if (!st_rrotate_ab(a, 0))
		return (0);
	if (!st_rrotate_ab(b, 0))
		return (0);
	ft_putstr_fd("rrr\n", 1);
	return (1);
}
