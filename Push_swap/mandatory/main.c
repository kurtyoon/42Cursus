/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 22:01:57 by cyun              #+#    #+#             */
/*   Updated: 2023/02/14 16:29:06 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_pivot	get_pivot(t_stack *a, int size)
{
	t_pivot		pivot;
	int			*arr;
	int			term;

	arr = copy_arr(a, size);
	bubble_sort(arr, size);
	term = size / 3;
	if (size % 3 == 2)
		term++;
	pivot.p1 = arr[term - 1];
	pivot.p2 = arr[term * 2 - 1];
	free(arr);
	return (pivot);
}

static void	divide_three(t_stack *a, t_stack *b)
{
	t_pivot		pivot;
	int			cnt;

	if (a->size > 5)
	{
		pivot = get_pivot(a, a->size);
		cnt = a->size;
		while (cnt-- && a->top > 2)
		{
			if (a->stack[a->top] <= pivot.p1)
			{
				stack_push_ab(a, b);
				stack_rotate_ab(b, 1);
			}
			else if (a->stack[a->top] <= pivot.p2)
				stack_push_ab(a, b);
			else
				stack_rotate_ab(a, 1);
		}
	}
	while (a->top > 2)
		stack_push_ab(a, b);
	if (a->top == 2)
		sort_three(a);
}

static void	greedy(t_stack *a, t_stack *b)
{
	int	move_a;
	int	move_b;

	while (b->top >= 0)
	{
		set_min_rotate(a, b, &move_a, &move_b);
		greedy_rotate(a, b, move_a, move_b);
		stack_push_ab(b, a);
	}
	last_rotate(a);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return (0);
	parse_argument(&a, &b, argv, argc);
	if (!check_sorted(&a))
	{
		if (a.size == 3)
			sort_three(&a);
		else if (a.size == 5)
			sort_five(&a, &b);
		else
		{
			divide_three(&a, &b);
			greedy(&a, &b);
		}
	}
	free(a.stack);
	free(b.stack);
	return (0);
}
