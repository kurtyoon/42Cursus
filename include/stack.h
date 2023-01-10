/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:30:05 by cyun              #+#    #+#             */
/*   Updated: 2023/01/10 16:54:01 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include "ft_printf/include/ft_printf.h"
# include "get_next_line/include/get_next_line.h"

void	*st_pop(t_list **stack);
int		st_push(t_list **stack, void *newcontent, size_t size);
t_list	*st_newstack(void *newcontent, size_t size);
int		st_printstack_ab(t_list *a, t_list *b, char *base);
int		st_swap_ab(t_list **stack, char c);
int		st_swap_ss(t_list **a, t_list **b);
int		st_push_ab(t_list **a, t_list **b, char c);
int		st_rotate_ab(t_list **stack, char c);
int		st_rotate_rr(t_list **a, t_list **b);
int		st_rrotate_ab(t_list **stack, char c);
int		st_rrotate_rrr(t_list **a, t_list **b);
int		st_find(t_list *stack, void *content, size_t size);
int		st_is_ordered(t_list *stack);
int		st_to_top(t_list **stack, void *content, char c);
t_list	*st_min(t_list *stack);
t_list	*st_max(t_list *stack);
t_list	*st_get_idx(t_list *stack, int index);
void	st_update(t_list **stack, int index, void *nw, int size);

#endif