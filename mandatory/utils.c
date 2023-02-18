/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 22:09:01 by cyun              #+#    #+#             */
/*   Updated: 2023/02/18 13:41:54 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	*copy_arr(t_stack *a, int size)
{
	int	*arr;
	int	idx;

	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		exit(1);
	idx = -1;
	while (++idx < a->top)
		arr[idx] = a->stack[a->top - idx];
	return (arr);
}

int	compare_number(int a, int b, int c)
{
	if (a > c && b > c && a > b)
		return (1);
	if (a < c && b > c && a < b)
		return (1);
	if (a < c && b < c && a > b)
		return (1);
	return (0);
}

int	append_data(char *str, int *result)
{
	int			i;
	long long	num;
	int			sign;

	i = 0;
	num = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	if (!str[i])
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
		num = num * 10 + (str[i++] - '0') * sign;
	if (str[i] != '\0' || num > 2147483647 || num < -2147483648)
		return (0);
	*result = num;
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
