# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/08 15:27:07 by cyun              #+#    #+#              #
#    Updated: 2023/01/14 18:35:41 by cyun             ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libgnl.a

INCS = include
SRCS = mandatory/get_next_line.c mandatory/get_next_line_utils.c
SRCSB = bonus/get_next_line_bonus.c bonus/get_next_line_utils_bonus.c
OBJS = $(SRCS:.c=.o)
OBJSB = $(SRCSB:.c=.o)

ifdef WITH_BONUS
		SOURCE = $(SRCSB)
		OBJECT = $(OBJSB)
	else
		SOURCE = $(SRCS)
		OBJECT = $(OBJS)
endif

all: $(NAME)

$(NAME): $(OBJECT)
	ar rc $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCS)

clean:
	rm -rf $(OBJS) $(OBJSB)

fclean: clean
	rm -rf $(NAME)

re: fclean all

bonus:
	make WITH_BONUS=1 all

.PHONY: all clean fclean re bonus
