/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 00:43:07 by cyun              #+#    #+#             */
/*   Updated: 2023/01/21 19:23:28 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	init_arr(int **arr, int **check, t_deque *a)
{
	t_node	*tmp;
	int		i;

	*arr = (int *)malloc(sizeof(int) * a->size);
	*check = (int *)malloc(sizeof(int) * a->size); // arr과 check를 덱의 크기만큼 할당
	if (arr == NULL || check == NULL)
		exit(1);
	tmp = a->top;
	i = 0;
	while (i < a->size) // 덱의 사이즈 만큼
	{
		(*arr)[i] = tmp->data; // arr에는 데이터 입력
		(*check)[i] = 0; // check에는 0으로 초기화
		tmp = tmp->next; // 덱 순회
		i++;
	}
}

// 덱 구조체 초기화 함수
void	init_deque(t_deque *a, t_deque *b)
{
	a->top = NULL;
	a->bottom = NULL;
	b->top = NULL;
	b->bottom = NULL;
	a->size = 0;
	b->size = 0;
	a->name = 'a';
	b->name = 'b';
}

// 덱이 정렬되어있는지
int	deque_is_sorted(t_deque *a, t_deque *b)
{
	t_node	*tmp;
	int		i;

	if (b->size) // b가 비어있지 않다면
		return (0);
	tmp = a->top;
	i = 0;
	while (i < a->size - 1)
	{
		if (tmp->data > tmp->next->data) // 정렬이 되어있지 않다면
			return (0);
		i++;
		tmp = tmp->next; // 덱 순회
	}
	return (1); // 정렬이 되어있다면 1 반환
}
