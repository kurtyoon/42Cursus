/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 22:10:14 by cyun              #+#    #+#             */
/*   Updated: 2023/02/14 16:21:41 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_sorted(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->top)
	{
		if (a->stack[i] < a->stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	bubble_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	sort_three(t_stack *a)
{
	if (a->stack[2] > a->stack[1])
		stack_swap_ab(a, 1);
	if (a->stack[1] > a->stack[0])
	{
		stack_rrotate_ab(a, 1);
		if (a->stack[2] > a->stack[1])
			stack_swap_ab(a, 1);
	}
}

void	sort_five(t_stack *a, t_stack *b)
{
	int	*arr;
	int	idx;

	idx = -1;
	arr = copy_arr(a, 5);
	bubble_sort(arr, 5);
	while (++idx < 5)
	{
		if (arr[1] >= a->stack[a->top])
			stack_push_ab(a, b);
		else
			stack_rotate_ab(a, 1);
	}
	sort_three(a);
	if (b->stack[0] > b->stack[1])
		stack_swap_ab(b, 1);
	stack_push_ab(b, a);
	stack_push_ab(b, a);
	free(arr);
}
