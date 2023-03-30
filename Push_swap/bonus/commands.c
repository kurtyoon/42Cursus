/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:47:33 by cyun              #+#    #+#             */
/*   Updated: 2023/02/17 00:29:33 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

int	classify_command(t_stack *a, t_stack *b, char *command)
{
	if (ft_strcmp(command, "sa\n") == 0)
		stack_swap_ab(a);
	else if (ft_strcmp(command, "sb\n") == 0)
		stack_swap_ab(b);
	else if (ft_strcmp(command, "ss\n") == 0)
		stack_swap_ss(a, b);
	else if (ft_strcmp(command, "pa\n") == 0)
		stack_push_ab(b, a);
	else if (ft_strcmp(command, "pb\n") == 0)
		stack_push_ab(a, b);
	else if (ft_strcmp(command, "ra\n") == 0)
		stack_rotate_ab(a);
	else if (ft_strcmp(command, "rb\n") == 0)
		stack_rotate_ab(b);
	else if (ft_strcmp(command, "rr\n") == 0)
		stack_rotate_rr(a, b);
	else if (ft_strcmp(command, "rra\n") == 0)
		stack_rrotate_ab(a);
	else if (ft_strcmp(command, "rrb\n") == 0)
		stack_rrotate_ab(b);
	else if (ft_strcmp(command, "rrr\n") == 0)
		stack_rrotate_rrr(a, b);
	else
		return (-1);
	return (0);
}

void	receive_command(t_stack *a, t_stack *b)
{
	char	*command;

	while (1)
	{
		command = get_next_line(0);
		if (!command)
			break;
		if (classify_command(a, b, command) == -1)
			ft_print_err("Error\n");
		free(command);
	}
}
