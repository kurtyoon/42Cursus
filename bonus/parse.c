/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:48:31 by cyun              #+#    #+#             */
/*   Updated: 2023/02/07 15:23:27 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	receive_input(t_deque *a, int argc, char **argv)
{
	char	**p;
	char	**save_p;
	int		i;

	if (argc == 2)
	{
		p = ft_split(argv[1], ' ');
		save_p = p;
		while (*p)
		{
			append_data(a, ft_atoi(*p));
			free(*p);
			p++;
		}
		free(save_p);
	}
	else
	{
		i = 0;
		while (++i < argc)
			append_data(a, ft_atoi(argv[i]));
	}
}

void	append_data(t_deque *x, int data)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		exit(1);
	new_node->prev = NULL;
	new_node->next = NULL;
	new_node->data = data;
	if (!(x->top))
	{
		x->top = new_node;
		x->bottom = new_node;
	}
	else
	{
		x->bottom->next = new_node;
		new_node->prev = x->bottom;
		new_node->next = x->top;
		x->top->prev = new_node;
		x->bottom = new_node;
	}
	x->size++;
}

static void	init_var(char **tmp, char **commands, char ***result)
{
	*tmp = malloc(sizeof(char));
	if (*tmp == NULL)
		exit(1);
	*(*tmp) = '\0';
	*commands = NULL;
	*result = NULL;
}

char	**read_commands(void)
{
	char	*commands;
	char	*tmp;
	char	*buff;
	char	**result;

	init_var(&tmp, &commands, &result);
	while (1)
	{
		buff = get_next_line(0);
		if (buff == NULL)
			break ;
		commands = ft_strjoin(tmp, buff);
		free(tmp);
		free(buff);
		tmp = commands;
	}
	if (commands)
	{
		result = ft_split(commands, '\n');
		free(commands);
	}
	else
		free(tmp);
	return (result);
}

int	classify_command(t_deque *a, t_deque *b, char *command)
{
	if (ft_strcmp(command, "sa") == 0)
		deque_swap_ab(a);
	else if (ft_strcmp(command, "sb") == 0)
		deque_swap_ab(b);
	else if (ft_strcmp(command, "ss") == 0)
		deque_swap_ss(a, b);
	else if (ft_strcmp(command, "pa") == 0)
		deque_push_ab(a, b);
	else if (ft_strcmp(command, "pb") == 0)
		deque_push_ab(b, a);
	else if (ft_strcmp(command, "ra") == 0)
		deque_rotate_ab(a);
	else if (ft_strcmp(command, "rb") == 0)
		deque_rotate_ab(b);
	else if (ft_strcmp(command, "rr") == 0)
		deque_rotate_rr(a, b);
	else if (ft_strcmp(command, "rra") == 0)
		deque_rrotate_ab(a);
	else if (ft_strcmp(command, "rrb") == 0)
		deque_rrotate_ab(b);
	else if (ft_strcmp(command, "rrr") == 0)
		deque_rrotate_rrr(a, b);
	else
		return (-1);
	return (0);
}
