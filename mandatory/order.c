/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 01:00:05 by cyun              #+#    #+#             */
/*   Updated: 2023/01/19 00:36:17 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	find_dest(t_deque *a, t_node *src)
{
	t_node	*p;
	int		dest;

	p = a->top;
	dest = 0;
	while (p)
	{
		if (p->prev->data > src->data && \
			p->data > src->data && p->prev->data > p->data)
			break ;
		if (p->prev->data < src->data && \
			p->data > src->data && p->prev->data < p->data)
			break ;
		if (p->prev->data < src->data && \
			p->data < src->data && p->prev->data > p->data)
			break ;
		p = p->next;
		dest++;
	}
	if (dest > a->size / 2)
		dest = dest - a->size;
	return (dest);
}

int	is_better(int tmp_dest, int tmp_sttp, int dest, int sttp)
{
	int	cnt;
	int	tmp_cnt;

	tmp_cnt = ft_abs(tmp_dest) + ft_abs(tmp_sttp);
	cnt = ft_abs(dest) + ft_abs(sttp);
	if (tmp_cnt < cnt)
		return (1);
	return (0);
}

void	get_location(t_deque *a, t_deque *b, int *dest, int *sttp)
{
	int		i;
	int		tmp_dest;
	int		tmp_sttp;
	t_node	*p;

	i = 0;
	p = b->top;
	while (i < b->size)
	{
		tmp_dest = find_dest(a, p);
		tmp_sttp = i;
		if (tmp_sttp > b->size / 2)
			tmp_sttp = i - b->size;
		if (i == 0 || is_better(tmp_dest, tmp_sttp, *dest, *sttp))
		{
			*dest = tmp_dest;
			*sttp = tmp_sttp;
		}
		p = p->next;
		i++;
	}
}

void	greedy_rotate(t_deque *a, t_deque *b, int dest, int sttp)
{
	if (dest == sttp)
	{
		while (dest > 0)
		{
			deque_rotate_rr(a, b);
			dest--;
		}
		while (dest++ < 0)
			deque_rrotate_rrr(a, b);
		return ;
	}
	while (dest > 0)
	{
		deque_rotate_ab(a);
		dest--;
	}
	while (dest++ < 0)
		deque_rrotate_ab(a);
	while (sttp > 0)
	{
		deque_rotate_ab(b);
		sttp--;
	}
	while (sttp++ < 0)
		deque_rrotate_ab(b);
}

void	last_rotate(t_deque *a)
{
	int		turning_point;
	t_node	*p;

	turning_point = 1;
	p = a->top;
	while (turning_point < a->size)
	{
		if (p->data > p->next->data)
			break ;
		turning_point++;
		p = p->next;
	}
	if (turning_point >= a->size / 2)
	{
		while (a->bottom->data < a->top->data)
			deque_rrotate_ab(a);
	}
	else
	{
		while (a->bottom->data < a->top->data)
			deque_rotate_ab(a);
	}
}
