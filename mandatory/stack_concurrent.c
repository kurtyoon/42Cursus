/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_concurrent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 21:58:23 by cyun              #+#    #+#             */
/*   Updated: 2023/02/12 19:02:24 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	stack_swap_ss(t_stack *a, t_stack *b)
{
	stack_swap_ab(a, 0);
	stack_swap_ab(b, 0);
	ft_printf("ss\n");
}

void	stack_rotate_rr(t_stack *a, t_stack *b)
{
	stack_rotate_ab(a, 0);
	stack_rotate_ab(b, 0);
	ft_printf("rr\n");
}

void	stack_rrotate_rrr(t_stack *a, t_stack *b)
{
	stack_rrotate_ab(a, 0);
	stack_rrotate_ab(b, 0);
	ft_printf("rrr\n", 4);
}
