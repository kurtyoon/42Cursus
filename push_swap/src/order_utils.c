/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:46:10 by cyun              #+#    #+#             */
/*   Updated: 2022/11/01 15:21:06 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// Check Stack is ordered.
int	st_is_ordered(t_list *stack)
{
	void	*prev;

	prev = NULL;
	if (!stack)
		return (0);
	while (stack)
	{
		if (prev && *(int *)prev > *(int *)stack->content)
			return (0);
		prev = stack->content;
		stack = stack->next;
	}
	return (1);
}

int	st_to_top(t_list **stack, void *content, char c)
{
	int		pos;
	void	*aux;

	aux = (void *)malloc(sizeof(int));
	if (!aux)
		return (0);
	ft_memcpy(aux, content, sizeof(int));
	pos = st_find(*stack, content, sizeof(int));
	if (*(int *)stack[0]->content != *(int *)aux && pos != -1)
	{
		while (ft_memcmp(aux, stack[0]->content, sizeof(int)))
		{
			if (pos > (ft_lstsize(*stack) - 1) / 2)
				st_rrotate_ab(stack, c);
			else
				st_rotate_ab(stack, c);
		}
	}
	free(aux);
	return (0);
}

void	st_translate(t_list **stack)
{
	t_list	*aux;
	int		len;
	int		i;
	int		content;

	i = 0;
	content = 0;
	aux = NULL;
	len = ft_lstsize(*stack);
	while (i++ < len)
		ft_lstadd_front(&aux, st_newstack((void *)&content, sizeof(int)));
	i = 0;
	content = *(int *)st_max(*stack)->content + 1;
	while (i < len)
	{
		st_update(&aux, st_find(*stack, st_min(*stack)->content, \
			sizeof(int)), (void *)&i, sizeof(int));
		st_update(stack, st_find(*stack, st_min(*stack)->content, \
			sizeof(int)), (void *)&content, sizeof(int));
		i++;
		content++;
	}
	ft_lstclear(stack, free);
	*stack = aux;
}

int	st_get_ordered(t_list *a, t_list *b, char c)
{
	int	len;
	int	count;

	count = 0;
	len = 0;
	while (c == 'a' && a)
	{
		if (*(int *)a -> content == len)
			count++;
		else
			count = 0;
		len++;
		a = a->next;
	}
	len = ft_lstsize(b) - 1;
	while (c == 'b' && b)
	{
		if (*(int *)b->content == len)
			count++;
		else
			count = 0;
		len--;
		b = b->next;
	}
	return (count);
}
