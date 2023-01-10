/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:19:22 by cyun              #+#    #+#             */
/*   Updated: 2023/01/10 15:54:42 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// If Stack->content is equal to content, return content's index
int	st_find(t_list *stack, void *content, size_t size)
{
	int	index;

	index = 0;
	while (stack)
	{
		if (!ft_memcmp(stack->content, content, size))
			return (index);
		stack = stack->next;
		index++;
	}
	return (-1);
}

// Return min value at stack
t_list	*st_min(t_list *stack)
{
	t_list	*min;

	min = NULL;
	while (stack)
	{
		if (!min || *(int *)min->content > *(int *)stack->content)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

// Return Max value at stack
t_list	*st_max(t_list *stack)
{
	t_list	*max;

	max = NULL;
	while (stack)
	{
		if (!max || *(int *)max->content < *(int *)stack->content)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

// Return Stack's (idx)th node
t_list	*st_get_idx(t_list *stack, int idx)
{
	int	index;

	index = 0;
	while (stack)
	{
		if (index == idx)
			return (stack);
		index++;
		stack = stack->next;
	}
	return (NULL);
}

// Change (index)th content to newcontent
void	st_update(t_list **stack, int index, void *newcontent, int size)
{
	t_list	*start;
	int		i;

	i = 0;
	start = *stack;
	while (start)
	{
		if (i == index)
		{
			free(start->content);
			start->content = NULL;
			start->content = (void *)malloc(size);
			ft_memcpy(start->content, newcontent, size);
			break ;
		}
		i++;
		start = start->next;
	}
}
