/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:36:12 by cyun              #+#    #+#             */
/*   Updated: 2022/11/01 15:42:20 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/stack.h"

// swap a or swap b
int	st_swap_ab(t_list **stack, char c)
{
	void	*tmp;
	t_list	*head;

	head = *stack;
	if (ft_lstsize(*stack) > 1)
	{
		tmp = head->content;
		head->content = head->next->content;
		head->next->content = tmp;
		if (c == 'a')
			ft_putstr_fd("sa\n", 1);
		if (c == 'b')
			ft_putstr_fd("sb\n", 1);
		return (1);
	}
	return (0);
}

// push a or push b
int	st_push_ab(t_list **a, t_list **b, char c)
{
	void	*tmp;

	if (ft_lstsize(*b))
	{
		tmp = st_pop(b);
		st_push(a, tmp, sizeof(int));
		free(tmp);
		if (c == 'a')
			ft_putstr_fd("pa\n", 1);
		if (c == 'b')
			ft_putstr_fd("pb\n", 1);
		return (1);
	}
	return (0);
}

// rotate a or rotate b
int	st_rotate_ab(t_list **stack, char c)
{
	void	*content;

	if (ft_lstsize(*stack) > 1)
	{
		content = st_pop(stack);
		ft_lstadd_back(stack, ft_lstnew(content));
		if (c == 'a')
			ft_putstr_fd("ra\n", 1);
		if (c == 'b')
			ft_putstr_fd("rb\n", 1);
		return (1);
	}
	return (0);
}

// rrotate a or rrotate b
int	st_rrotate_ab(t_list **stack, char c)
{
	void	*content;
	t_list	*last_a;
	t_list	*prev;

	if (ft_lstsize(*stack) > 1)
	{
		last_a = st_get_idx(*stack, ft_lstsize(*stack) - 1);
		prev = st_get_idx(*stack, ft_lstsize(*stack) - 2);
		content = last_a->content;
		st_push(stack, content, sizeof(int));
		ft_lstdelone(last_a, free);
		prev->next = NULL;
		if (c == 'a')
			ft_putstr_fd("rra\n", 1);
		if (c == 'b')
			ft_putstr_fd("rrb\n", 1);
		return (1);
	}
	return (0);
}
