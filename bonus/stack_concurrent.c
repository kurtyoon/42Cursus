/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_concurrent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 21:58:23 by cyun              #+#    #+#             */
/*   Updated: 2023/02/12 19:01:53 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	stack_swap_ss(t_stack *a, t_stack *b)
{
	stack_swap_ab(a);
	stack_swap_ab(b);
}

void	stack_rotate_rr(t_stack *a, t_stack *b)
{
	stack_rotate_ab(a);
	stack_rotate_ab(b);
}

void	stack_rrotate_rrr(t_stack *a, t_stack *b)
{
	stack_rrotate_ab(a);
	stack_rrotate_ab(b);
}
