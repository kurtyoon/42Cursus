/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 00:10:42 by cyun              #+#    #+#             */
/*   Updated: 2023/01/19 00:34:05 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	deque_add_top(t_deque *x, t_node *new_node)
{
	t_node	*p;

	p = x->top;
	x->top = new_node;
	new_node->next = p;
	x->size++;
	if (p == NULL)
	{
		x->bottom = new_node;
		new_node->prev = new_node;
		new_node->next = new_node;
		return ;
	}
	new_node->prev = x->bottom;
	p->prev = new_node;
	x->bottom->next = x->top;
}

void	deque_add_bottom(t_deque *x, t_node *new_node)
{
	t_node	*p;

	p = x->bottom;
	x->bottom = new_node;
	new_node->prev = p;
	x->size++;
	if (p == NULL)
	{
		x->top = new_node;
		new_node->prev = new_node;
		new_node->next = new_node;
		return ;
	}
	new_node->next = x->top;
	p->next = new_node;
	x->top->prev = x->bottom;
}

t_node	*deque_pop_top(t_deque *x)
{
	t_node	*p;
	t_node	*q;

	p = x->top;
	if (p == NULL)
		return (NULL);
	q = p->next;
	p->prev = NULL;
	p->next = NULL;
	x->top = q;
	x->size--;
	if (q == NULL || p == q)
	{
		x->top = NULL;
		x->bottom = NULL;
		return (p);
	}
	q->prev = x->bottom;
	x->bottom->next = q;
	return (p);
}

t_node	*deque_pop_bottom(t_deque *x)
{
	t_node	*p;
	t_node	*q;

	p = x->bottom;
	if (p == NULL)
		return (NULL);
	q = p->prev;
	p->prev = NULL;
	p->next = NULL;
	x->bottom = q;
	x->size--;
	if (q == NULL || p == q)
	{
		x->top = NULL;
		x->bottom = NULL;
		return (p);
	}
	q->next = x->top;
	x->top->prev = q;
	return (p);
}
