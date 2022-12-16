/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:51:22 by cyun              #+#    #+#             */
/*   Updated: 2022/11/01 15:34:31 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// atoi function, This fucntion prevents Overflow
int	st_parse_input(const char *str, long *nbr)
{
	int	sign;

	sign = 1;
	*nbr = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	if (!ft_isdigit(*str))
		return (-1);
	while (ft_isdigit(*str))
	{
		*nbr = 10 * *nbr + (*str - '0');
		if (*nbr > INT_MAX && sign == 1)
			return (-1);
		if (*nbr > -INT_MIN && sign == -1)
			return (-1);
		str++;
	}
	if (*str && !ft_isspace(*str))
		return (-1);
	*nbr *= sign;
	return (0);
}

// Checking inputs.
int	st_check_value(char *argv, t_list **a)
{
	int		j;
	long	content;

	j = 0;
	while (argv[j])
	{
		if (st_parse_input(&argv[j], &content) == -1 || \
			st_find(*a, (void *)&content, sizeof(int)) != -1)
		{
			ft_lstclear(a, free);
			ft_putstr_fd("Error\n", 1);
			return (-1);
		}
		ft_lstadd_back(a, st_newstack((void *)&content, sizeof(int)));
		while (ft_isspace(argv[j]))
			j++;
		j += ft_strchr("+-", argv[j]) != 0;
		while (ft_isdigit(argv[j]))
			j++;
	}
	return (0);
}

// Parsing inputs. Prevent only one input.
t_list	*st_parse(int argc, char **argv)
{
	t_list	*a;
	int		i;

	a = NULL;
	i = 0;
	if (argc < 3)
		return (NULL);
	while (++i < argc)
	{
		if (st_check_value(argv[i], &a) == -1)
			return (NULL);
	}
	return (a);
}

// Parsing, Sorting, Free
int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	b = NULL;
	a = st_parse(argc, argv);
	if (!a)
		return (0);
	st_order(&a, &b);
	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
	return (0);
}
