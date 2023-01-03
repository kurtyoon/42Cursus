/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:27:14 by cyun              #+#    #+#             */
/*   Updated: 2022/10/05 10:06:40 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count <= 0 || size <= 0)
		ptr = (char *)malloc(1);
	else
		ptr = (char *)malloc(count * size);
	if (!ptr)
		return (NULL);
	return (ft_memset(ptr, 0, count * size));
}
