/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:25:57 by cyun              #+#    #+#             */
/*   Updated: 2022/07/22 15:57:44 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*buf_src;
	unsigned char	*buf_dst;
	size_t			i;

	i = 0;
	buf_src = (unsigned char *)src;
	buf_dst = (unsigned char *)dst;
	if (dst == 0 && src == 0)
		return (0);
	while (i < len)
	{
		if (src > dst)
			buf_dst[i] = buf_src[i];
		else
			buf_dst[len - 1 - i] = buf_src[len - 1 - i];
		i++;
	}
	return (buf_dst);
}
