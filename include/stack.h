/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 21:55:32 by cyun              #+#    #+#             */
/*   Updated: 2023/02/10 22:01:45 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "ft_printf/include/ft_printf.h"
# include "get_next_line/include/get_next_line.h"

typedef struct	s_stacks
{
	int			*stack;
	int			top;
	int			size;
	char		name;
}				t_stacks;

// stack_operation.c
void	stack_swap_ab(t_stacks *stack);
void	stack_push_ab(t_stacks *from, t_stacks *to);
void	stack_rotate_ab(t_stacks *stack);
void	stack_rrotate_ab(t_stacks *stack);

// stack_concurrent.c
void	stack_rotate_rr(t_stacks *a, t_stacks *b);
void	stack_rrotate_rrr(t_stacks *a, t_stacks *b);
void	stack_swap_ss(t_stacks *a, t_stacks *b);

#endif