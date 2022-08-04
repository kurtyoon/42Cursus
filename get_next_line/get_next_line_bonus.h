/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 15:11:53 by cyun              #+#    #+#             */
/*   Updated: 2022/08/04 21:53:51 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFSE_SIZE 5000
# endif

char	*get_next_line(int fd);
char	*get_line(char *backup);
char	*backup_next(char *backup);
char	*read_and_store(int fd, char *backup);

char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);

#endif