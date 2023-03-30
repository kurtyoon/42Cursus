/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:45:42 by cyun              #+#    #+#             */
/*   Updated: 2023/02/14 16:19:21 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

int	find_size(const char *str)
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

void	ft_free_malloc(char **result, size_t k)
{
	size_t	i;

	i = 0;
	while (i < k)
	{
		free(result[i]);
		i++;
	}
	free(result);
}

int	append_data(char *str, int *result)
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

void	parse_argument(t_stack *a, t_stack *b, int argc, char **argv)
{
	int		i;
	int		tmp_i;
	int		size;
	char	**tmp;

	size = 0;
	i = 1;
	while (i < argc)
		size += find_size(argv[i++]);
	init_stacks(a, b, size);
	i = 1;
	while (i < argc)
	{
		tmp_i = 0;
		tmp = ft_split(argv[i++], ' ');
		while (tmp[tmp_i])
		{
			if (!append_data(tmp[tmp_i++], &a->stack[++a->top])
				|| !check_duplicate(a))
				ft_print_err("Error\n");
		}
		ft_free_malloc(tmp, tmp_i);
	}
	swap_stack(a);
}
