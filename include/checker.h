/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:05:16 by cyun              #+#    #+#             */
/*   Updated: 2023/02/12 13:06:13 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "ft_printf/include/ft_printf.h"
# include "get_next_line/include/get_next_line.h"

typedef struct	s_stacks
{
	int			*stack;
	int			top;
	int			size;
	char		name;
}				t_stacks;

#endif