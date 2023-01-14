/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:36:05 by cyun              #+#    #+#             */
/*   Updated: 2023/01/14 16:15:03 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "deque.h"
# define INT_MIN -2147483648
# define INT_MAX 2147483647

int		find_dest(t_deque *a, t_node *src);
int		is_better(int tmp_dest, int tmp_sttp, int dest, int sttp);
void	get_location(t_deque *a, t_deque *b, int *dest, int *sttp);
void	last_rotate(t_deque *a);
void	change_to_idx(t_deque *a);
void	receive_input(t_deque *a, int argc, char **argv);
void	append_data(t_deque *x, int data);
int	binary_search(int *arr, int data, int left, int right);
void	quick_sort(int *arr, int left, int right);

#endif