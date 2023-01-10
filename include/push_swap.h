/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:36:05 by cyun              #+#    #+#             */
/*   Updated: 2023/01/10 16:54:06 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "stack.h"
# define INT_MIN -2147483648
# define INT_MAX 2147483647

void	st_translate(t_list **stack);
int		st_order(t_list **a, t_list **b);
void	st_sort_small(t_list **a, t_list **b);
int		st_radix_sort(t_list **a, t_list **b, int max_len, int right_shift);
int		st_get_ordered(t_list *a, t_list *b, char c);

#endif