# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/12 22:11:43 by cyun              #+#    #+#              #
#    Updated: 2022/11/12 22:35:00 by cyun             ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
CC = cc
INC = inc
OBJ = $(SRC:.c=.o)
NAME = pipex
LIBFT = libft
LIBFT_LIB = libft.a

SRC = src/main.c src/pipex_utils.c src/pipex.c

.c.o: $(SRC)
	$(CC) $(CFLAGS) -c -o $@ $< -I$(INC)

$(NAME): $(OBJ)
	make bonus -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT)/$(LIBFT_LIB) -o $@

all: $(NAME)

clean:
	$(RM) $(OBJ)
	make clean -C $(LIBFT)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT)

re: fclean
	make all

.PHONY: all clean fclean re
