/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 22:09:01 by cyun              #+#    #+#             */
/*   Updated: 2023/02/10 22:09:17 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	*copy_arr(t_stacks *a, int size)
{
	int	*arr;
	int	idx;

	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		exit(1);
	idx = -1;
	while (++idx < size)
		arr[idx] = a->stack[a->top - idx];
	return (arr);
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

int	ft_free_malloc(char **result, size_t k)
{
	size_t	i;

	i = 0;
	while (i < k)
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (0);
}