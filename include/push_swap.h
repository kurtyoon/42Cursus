/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:36:05 by cyun              #+#    #+#             */
/*   Updated: 2023/02/12 19:08:35 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "stack.h"

typedef struct s_pivot
{
	int			p1;
	int			p2;
}				t_pivot;

int		check_duplicate(t_stack *a);
int		word_cnt(const char *str);
void	init_stacks(t_stack *a, t_stack *b, int size);
void	swap_stack(t_stack *a);
void	parse_argument(t_stack *a, t_stack *b, char **argv, int argc);

int		*copy_arr(t_stack *a, int size);
int		append_data(char *str, int *result);
int		ft_free_malloc(char **result, size_t k);

int		check_sorted(t_stack *a);
void	bubble_sort(int *arr, int size);
void	sort_three(t_stack *a);
void	sort_five(t_stack *a, t_stack *b);

void	set_min_rotate(t_stack *a, t_stack *b, int *move_a, int *move_b);
int		compare_cnt(int pos_a, int pos_b, int move_a, int move_b);
void	greedy_rotate(t_stack *a, t_stack *b, int move_a, int move_b);
void	last_rotate(t_stack *a);
int		get_a_position(t_stack *a, int num);

#endif