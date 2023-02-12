/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:51:32 by cyun              #+#    #+#             */
/*   Updated: 2023/02/12 13:20:09 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	init_stacks(t_stacks *a, t_stacks *b, int size)
{
	a->stack = (int *)malloc(sizeof(int) * size);
	b->stack = (int *)malloc(sizeof(int) * size);
	a->top = -1;
	b->top = -1;
	a->size = size;
	b->size = size;
	a->name = 'a';
	b->name = 'b';
	if (!a->stack || !b->stack)
		exit(1);
}

int	word_cnt(const char *str)
{
	size_t	size;
	int		flag;

	size = 0;
	flag = 1;
	while (*str)
	{
		if (flag && *str != ' ')
		{
			size++;
			flag = 0;
		}
		if (*str == ' ')
			flag = 1;
		str++;
	}
	if (!size)
		ft_print_err("Error\n");
	return (size);
}

int	ft_atoi2(char *str, int *result)
{
	long long	tmp;
	int			sign;

	tmp = 0;
	sign = 1;
	while ((9 <= *str && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!*str)
		return (0);
	while ('0' <= *str && *str <= '9')
	{
		tmp *= 10;
		tmp += (*str - '0') * sign;
		str++;
	}
	if (*str != '\0' || tmp > 2147483647 || tmp < -2147483648)
		return (0);
	*result = tmp;
	return (1);
}

void	parse_argument(t_stacks *a, t_stacks *b, int argc, char **argv)
{
	int		i;
	int		tmp_i;
	int		size;
	char	**tmp;

	size = 0;
	i = 1;
	if (argc == 1)
		exit(0);
	while (i < argc)
		size += word_cnt(argv[i++]);
	init_stacks(a, b, size);
	i = 1;
	while (i < argc)
	{
		tmp_i = 0;
		tmp = ft_split(argv[i++], ' ');
		while (tmp[tmp_i])
		{
			if (!ft_atoi2(tmp[tmp_i], &a->stack[++a->top])
				|| !check_duplicate(a))
				ft_print_err("Error\n");
		}
	}
	receive_input(a, argc, argv);
	change_to_idx(a);
}

int	check_sorted(t_stacks *a, t_stacks *b)
{
	int		i;
	t_node	*p;

	if (b->size)
		return (0);
	p = a->top;
	i = 0;
	while (i < a->size - 1)
	{
		if (p->data > p->next->data)
			return (0);
		i++;
		p = p->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stacks		a;
	t_stacks		b;
	char		**commands;

	parse_argument(&a, &b, argc, argv);
	commands = read_commands();
	execute_commands(&a, &b, commands);
	if (check_sorted(&a, &b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free(a.stack);
	free(b.stack);
	return (0);
}
