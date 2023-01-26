/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:36:05 by cyun              #+#    #+#             */
/*   Updated: 2023/01/23 22:18:05 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "deque.h"

// order.c
int		get_position(t_deque *a, t_node *src);
int		compare_cnt(int pos_a, int pos_b, int move_a, int move_b);
void	get_location(t_deque *a, t_deque *b, int *move_a, int *move_b);
void	last_rotate(t_deque *a);

// parse.c
void	deque_is_duplicated(t_deque *a);
void	receive_input(t_deque *a, int argc, char **argv);
void	deque_insert_data(t_deque *x, int data);
int		binary_search(int *arr, int data, int left, int right);
void	quick_sort(int *arr, int left, int right);

#endif