/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:05:16 by cyun              #+#    #+#             */
/*   Updated: 2023/02/12 15:00:49 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
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

// commands.c
int		classify_command(t_stacks *a, t_stacks *b, char *command);
char	**read_commands();
void	execute_commands(t_stacks *a, t_stacks *b, char **commands);
void	operator(t_stacks *a, t_stacks *b, char *commands);

// parse.c
void	parse_argument(t_stacks *a, t_stacks *b, int argc, char **argv);
int		word_cnt(const char *str);
void	ft_free_malloc(char **result, size_t k);
int		append_data(char *str, int *result);

// checker.c
void	init_stacks(t_stacks *a, t_stacks *b, int size);
void	swap_stack(t_stacks *a);
int	check_duplicate(t_stacks *a);
int	check_sorted(t_stacks *a);

#endif