/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:47:33 by cyun              #+#    #+#             */
/*   Updated: 2023/02/12 18:56:44 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

static void	init_var(char **tmp, char **commands, char ***result)
{
	*tmp = malloc(sizeof(char));
	if (*tmp == NULL)
		exit(1);
	*(*tmp) = '\0';
	*commands = NULL;
	*result = NULL;
}

int	classify_command(t_stack *a, t_stack *b, char *command)
{
	if (ft_strcmp(command, "sa") == 0)
		stack_swap_ab(a);
	else if (ft_strcmp(command, "sb") == 0)
		stack_swap_ab(b);
	else if (ft_strcmp(command, "ss") == 0)
		stack_swap_ss(a, b);
	else if (ft_strcmp(command, "pa") == 0)
		stack_push_ab(b, a);
	else if (ft_strcmp(command, "pb") == 0)
		stack_push_ab(a, b);
	else if (ft_strcmp(command, "ra") == 0)
		stack_rotate_ab(a);
	else if (ft_strcmp(command, "rb") == 0)
		stack_rotate_ab(b);
	else if (ft_strcmp(command, "rr") == 0)
		stack_rotate_rr(a, b);
	else if (ft_strcmp(command, "rra") == 0)
		stack_rrotate_ab(a);
	else if (ft_strcmp(command, "rrb") == 0)
		stack_rrotate_ab(b);
	else if (ft_strcmp(command, "rrr") == 0)
		stack_rrotate_rrr(a, b);
	else
		return (-1);
	return (0);
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

void	execute_commands(t_stack *a, t_stack *b, char **commands)
{
	char	**p;

	if (commands == NULL)
		return ;
	p = commands;
	while (*commands)
	{
		if (classify_command(a, b, *commands) == -1)
		{
			ft_printf("Error\n");
			exit(1);
		}
		free(*commands);
		commands++;
	}
	free(p);
}

void	operator(t_stack *a, t_stack *b, char *commands)
{
	if (classify_command(a, b, commands) == -1)
		ft_print_err("Error\n");
	free(commands);
}
