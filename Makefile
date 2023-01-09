# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 13:39:25 by hykang            #+#    #+#              #
#    Updated: 2023/01/09 15:30:01 by cyun             ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude
NAME = so_long

SRCS =	srcs/main.c srcs/draw.c srcs/init.c \
		srcs/map.c srcs/player.c srcs/utils.c srcs/path.c
SRCSB =	srcsb/main_bonus.c srcsb/draw_bonus.c srcsb/init_bonus.c \
		srcsb/map_bonus.c srcsb/player_bonus.c srcsb/utils_bonus.c \
		srcsb/path_bonus.c
OBJS = $(SRCS:.c=.o)
OBJSB = $(SRCSB:.c=.o)

MLX_NAME = mlx
MLX_DIR = ./include/mlx
GNL_NAME = gnl
GNL_DIR = ./include/get_next_line

ifdef WITH_BONUS
		SOURCE = $(SRCSB)
	else
		SOURCE = $(SRCS)
endif

all: $(NAME)

$(NAME): $(SOURCE)
	make -C $(MLX_DIR) all
	make -C $(GNL_DIR) all
	$(CC) $(CFLAGS) -L$(MLX_DIR) -l$(MLX_NAME) \
		-L$(GNL_DIR) -l$(GNL_NAME) \
		-framework OpenGL -framework AppKit -g $^ -o $@

%.o : %.c
	$(CC) $(CFLAGS) -I$(MLX_DIR) -I$(GNL_DIR) -c $< -o $@

clean:
	rm -f *.o
	make -C $(MLX_DIR) clean
	make -C $(GNL_DIR) clean

fclean: clean
	rm -f $(NAME) $(OBJS)
	make -C $(MLX_DIR) clean
	make -C $(GNL_DIR) fclean

re: fclean all

bonus: 
	make WITH_BONUS=1 all

.PHONY: all clean fclean re bonus
