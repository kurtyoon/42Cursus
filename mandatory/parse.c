/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:05:08 by cyun              #+#    #+#             */
/*   Updated: 2023/02/07 16:40:49 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	deque_is_duplicated(t_deque *a)
{
	int		*arr;
	int		*check;
	int		i;
	t_node	*tmp;

	init_arr(&arr, &check, a);
	quick_sort(arr, 0, a->size - 1);
	tmp = a->top;
	i = 0;
	while (i < a->size)
	{
		tmp->data = binary_search(arr, tmp->data, 0, a->size - 1); // 이진 탐색으로 인덱스를 가져옴
		if (check[tmp->data] == 0) // 해당 인덱스 값이 0 이라면 중복 x
			check[tmp->data] = 1;
		else // 아닐 경우 중복을 의미
		{
			free_node(a);
			ft_print_err("Error\n");
		}
		tmp = tmp->next; // 덱 순회
		i++;
	}
	free(arr);
	free(check);
}

// void	receive_input(t_deque *a, int argc, char **argv)
// {
// 	char	**args;
// 	int		i;

// 	if (argc == 2) // 인자가 2개일 때 '1 2 3 4 5' 이런 식으로 입력
// 	{
// 		args = ft_split(argv[1], ' '); // ' '을 기준으로 split해서 저장
// 		while (*args)
// 		{
// 			deque_insert_data(a, ft_atoi(*args)); // split으로 쪼갠 숫자들을 atoi로 정수화 해서 데이터 입력
// 			args++;
// 		}
// 	}
// 	else // 1 2 3 4 5 이런 식으로 입력
// 	{
// 		i = 0;
// 		while (++i < argc) // 그대로 정수화 해서 데이터 입력
// 			deque_insert_data(a, ft_atoi(argv[i]));
// 	}
// }

int	ft_free_malloc(char **result, size_t k)
{
	size_t	i;

	i = 0;
	while (i < k)
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (0);
}

void	receive_input(t_deque *a, int argc, char **argv)
{
	char	**args;
	int		i;
	int		tmp;

	i = 0;
	while (++i < argc) {
		tmp = 0;
		args = ft_split(argv[i], ' ');
		while (args[tmp]) {
			deque_insert_data(a, ft_atoi(args[tmp++]));
		}
		ft_free_malloc(args, tmp);
	}
}

void	deque_insert_data(t_deque *a, int data)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
		exit(1);
	new_node->prev = NULL;
	new_node->next = NULL;
	new_node->data = data;
	if (!(a->top)) // 덱 a에 요소가 없다면
	{
		a->top = new_node;
		a->bottom = new_node; // top과 bottom에 입력
	}
	else // 있다면
	{
		a->bottom->next = new_node;
		new_node->prev = a->bottom;
		new_node->next = a->top;
		a->top->prev = new_node;
		a->bottom = new_node;
	}
	a->size++; // 덱 a의 크기 증가
}

// 이진탐색 코드
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

// 퀵 정렬 코드
void	quick_sort(int *arr, int left, int right)
{
	int	low;
	int	high;
	int	pivot;

	low = left;
	high = right;
	pivot = arr[(left + right) / 2];
	while (low <= high)
	{
		while (arr[low] < pivot)
			low++;
		while (arr[high] > pivot)
			high--;
		if (low <= high)
		{
			ft_swap(arr + low, arr + high);
			low++;
			high--;
		}
	}
	if (left < high)
		quick_sort(arr, left, high);
	if (right > low)
		quick_sort(arr, low, right);
}
