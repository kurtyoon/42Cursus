/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 00:22:20 by cyun              #+#    #+#             */
/*   Updated: 2023/01/14 16:11:32 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUE_H
# define DEQUE_H
# include "ft_printf/include/ft_printf.h"
# include "get_next_line/include/get_next_line.h"

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_deque
{
	t_node	*top;
	t_node	*bottom;
	char	name;
	int		size;
}	t_deque;

void	deque_add_top(t_deque *x, t_node *new_node);
void	deque_add_bottom(t_deque *x, t_node *new_node);
t_node	*deque_pop_top(t_deque *x);
t_node	*deque_pop_bottom(t_deque *x);
void	deque_swap_ab(t_deque *x);
void	deque_push_ab(t_deque *x, t_deque *y);
void	deque_rotate_ab(t_deque *x);
void	deque_rrotate_ab(t_deque *x);
void	deque_swap_ss(t_deque *x, t_deque *y);
void	deque_rotate_rr(t_deque *x, t_deque *y);
void	deque_rrotate_rrr(t_deque *x, t_deque *y);
void	ft_swap(int	*a, int *b);
void	init_arr(int **arr, int **dup_check, t_deque *a);
void	init_deque(t_deque *a, t_deque *b);
int	deque_is_sorted(t_deque *a, t_deque *b);
void	greedy_rotate(t_deque *a, t_deque *b, int dest, int sttp);

#endif
