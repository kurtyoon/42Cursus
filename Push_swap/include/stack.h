/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 21:55:32 by cyun              #+#    #+#             */
/*   Updated: 2023/02/12 19:09:04 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "ft_printf/include/ft_printf.h"
# include "get_next_line/include/get_next_line.h"

typedef struct s_stack
{
	int			*stack;
	int			top;
	int			size;
	char		name;
}				t_stack;

// stack_operation.c
void	stack_swap_ab(t_stack *stack, int flag);
void	stack_push_ab(t_stack *from, t_stack *to);
void	stack_rotate_ab(t_stack *stack, int flag);
void	stack_rrotate_ab(t_stack *stack, int flag);

// stack_concurrent.c
void	stack_rotate_rr(t_stack *a, t_stack *b);
void	stack_rrotate_rrr(t_stack *a, t_stack *b);
void	stack_swap_ss(t_stack *a, t_stack *b);

#endif