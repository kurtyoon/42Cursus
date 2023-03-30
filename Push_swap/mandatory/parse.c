/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 22:04:10 by cyun              #+#    #+#             */
/*   Updated: 2023/02/16 23:58:48 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

int	find_size(const char *str)
{
	size_t	size;
	int		flag;

	size = 0;
	flag = 1;
	while (*str)
	{
		if (flag && *str != ' ')
		{
			size++;
			flag = 0;
		}
		if (*str == ' ')
			flag = 1;
		str++;
	}
	if (!size)
		ft_print_err("Error\n");
	return (size);
}

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

void	parse_argument(t_stack *a, t_stack *b, char **argv, int argc)
{
	int		i;
	int		tmp_i;
	int		size;
	char	**tmp;

	size = 0;
	i = 1;
	while (i < argc)
		size += find_size(argv[i++]);
	init_stacks(a, b, size);
	i = 1;
	while (i < argc)
	{
		tmp_i = 0;
		tmp = ft_split(argv[i++], ' ');
		while (tmp[tmp_i])
		{
			if (!append_data(tmp[tmp_i++], &a->stack[++a->top])
				|| !check_duplicate(a))
				ft_print_err("Error\n");
		}
		ft_free_malloc(tmp, tmp_i);
	}
	swap_stack(a);
}
