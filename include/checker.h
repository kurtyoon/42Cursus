/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:05:16 by cyun              #+#    #+#             */
/*   Updated: 2023/01/19 00:36:47 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
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
void	change_to_idx(t_deque *a);
void	receive_input(t_deque *a, int argc, char **argv);
void	append_data(t_deque *x, int data);
int		binary_search(int *arr, int data, int left, int right);
void	quick_sort(int *arr, int left, int right);
void	init_arr(int **arr, int **dup_check, t_deque *a);
char	**read_commands(void);
int		classify_command(t_deque *a, t_deque *b, char *command);
void	execute_commands(t_deque *a, t_deque *b, char **commands);

#endif