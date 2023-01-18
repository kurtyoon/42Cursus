/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:05:08 by cyun              #+#    #+#             */
/*   Updated: 2023/01/14 18:33:49 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	execute_commands(t_deque *a, t_deque *b, char **commands)
{
	char	**p;

	if (commands == NULL)
		return ;
	p = commands;
	while (*commands)
	{
		if (classify_command(a, b, *commands) == -1)
		{
			ft_printf("Error\n");
			exit(1);
		}
		free(*commands);
		commands++;
	}
	free(p);
}

void	change_to_idx(t_deque *a)
{
	int		*arr;
	int		*dup_ck;
	int		i;
	t_node	*p;

	init_arr(&arr, &dup_ck, a);
	quick_sort(arr, 0, a->size - 1);
	p = a->top;
	i = 0;
	while (i < a->size)
	{
		p->data = binary_search(arr, p->data, 0, a->size - 1);
		if (dup_ck[p->data] == 0)
			dup_ck[p->data] = 1;
		else
		{
			ft_printf("Error\n");
			exit(1);
		}
		p = p->next;
		i++;
	}
	free(arr);
	free(dup_ck);
}

void	init_arr(int **arr, int **dup_check, t_deque *a)
{
	t_node	*p;
	int		i;

	*arr = malloc(sizeof(int) * a->size);
	*dup_check = malloc(sizeof(int) * a->size);
	if (arr == NULL || dup_check == NULL)
		exit(1);
	p = a->top;
	i = 0;
	while (i < a->size)
	{
		(*arr)[i] = p->data;
		(*dup_check)[i] = 0;
		p = p->next;
		i++;
	}
}

int	binary_search(int *arr, int data, int left, int right)
{
	int	mid;

	mid = (left + right) / 2;
	if (arr[mid] < data)
		return (binary_search(arr, data, mid + 1, right));
	else if (arr[mid] > data)
		return (binary_search(arr, data, left, mid - 1));
	else
		return (mid);
}

void	quick_sort(int *arr, int left, int right)
{
	int	l;
	int	r;
	int	pivot;

	l = left;
	r = right;
	pivot = arr[(left + right) / 2];
	while (l <= r)
	{
		while (arr[l] < pivot)
			l++;
		while (arr[r] > pivot)
			r--;
		if (l <= r)
		{
			ft_swap(arr + l, arr + r);
			l++;
			r--;
		}
	}
	if (left < r)
		quick_sort(arr, left, r);
	if (right > l)
		quick_sort(arr, l, right);
}
