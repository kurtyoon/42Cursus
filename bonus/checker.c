/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:51:32 by cyun              #+#    #+#             */
/*   Updated: 2023/02/17 00:20:38 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	init_stacks(t_stack *a, t_stack *b, int size)
{
	a->stack = (int *)malloc(sizeof(int) * size);
	b->stack = (int *)malloc(sizeof(int) * size);
	a->top = -1;
	b->top = -1;
	a->size = size;
	b->size = size;
	a->name = 'a';
	b->name = 'b';
	if (!a->stack || !b->stack)
		exit(1);
}

void	swap_stack(t_stack *a)
{
	int	left;
	int	right;
	int	tmp;

	left = 0;
	right = a->top;
	while (left < right)
	{
		tmp = a->stack[left];
		a->stack[left] = a->stack[right];
		a->stack[right] = tmp;
		left++;
		right--;
	}
}

int	check_duplicate(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->top)
	{
		if (a->stack[i] == a->stack[a->top])
			return (0);
		i++;
	}
	return (1);
}

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

int	main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;

	if (argc < 2)
		return (0);
	parse_argument(&a, &b, argc, argv);
	receive_command(&a, &b);
	if (check_sorted(&a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free(a.stack);
	free(b.stack);
	return (0);
}
