/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:39:01 by cyun              #+#    #+#             */
/*   Updated: 2023/01/10 15:54:47 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Pop Stack at first node
// If Stack is empty -> return NULL
void	*st_pop(t_list **stack)
{
	void	*res;
	t_list	*tmp;

	res = NULL;
	if (!stack || !stack[0])
		return (NULL);
	tmp = *stack;
	if (tmp->next)
	{
		*stack = tmp->next;
		res = tmp->content;
		free(tmp);
		return (res);
	}
	res = tmp->content;
	free(tmp);
	*stack = NULL;
	return (res);
}

// Push Stack at first node
int	st_push(t_list **stack, void *newcontent, size_t size)
{
	t_list	*newstack;

	newstack = st_newstack(newcontent, size);
	if (!newstack)
		return (0);
	ft_lstadd_front(stack, newstack);
	return (1);
}

// Init new Stack, and allocate content
t_list	*st_newstack(void *newcontent, size_t size)
{
	t_list	*newstack;
	void	*content;

	newstack = (t_list *)malloc(sizeof(t_list));
	if (!newstack)
		return (NULL);
	content = malloc(size);
	if (!content)
	{
		free(newstack);
		return (NULL);
	}
	ft_memcpy(content, newcontent, size);
	newstack->content = content;
	newstack->next = NULL;
	return (newstack);
}

// Make free Stack
void	st_freestack(t_list **stack)
{
	t_list	*tmp;

	tmp = NULL;
	if (*stack)
	{
		while (*stack)
		{
			tmp = *stack;
			stack[0] = stack[0]->next;
			free(tmp->content);
			free(tmp);
			tmp = NULL;
		}
	}
	*stack = NULL;
}
