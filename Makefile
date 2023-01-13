# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 13:39:25 by hykang            #+#    #+#              #
#    Updated: 2023/01/13 16:39:54 by cyun             ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude
NAME = so_long

SRCS =	mandatory/main.c mandatory/draw.c mandatory/init.c \
		mandatory/map.c mandatory/player.c mandatory/utils.c mandatory/path.c
SRCSB =	bonus/main_bonus.c bonus/draw_bonus.c bonus/init_bonus.c \
		bonus/map_bonus.c bonus/player_bonus.c bonus/utils_bonus.c \
		bonus/path_bonus.c
		
OBJS = $(SRCS:.c=.o)
OBJSB = $(SRCSB:.c=.o)

MLX_NAME = mlx
MLX_DIR = ./include/mlx
GNL_NAME = gnl
GNL_DIR = ./include/get_next_line

ifdef WITH_BONUS
		SOURCE = $(SRCSB)
		OBJECT = $(OBJSB)
	else
		SOURCE = $(SRCS)
		OBJECT = $(OBJS)
endif

all: $(NAME)

$(NAME): $(OBJECT)
	make -C $(MLX_DIR) all
	make -C $(GNL_DIR) all
	$(CC) $(CFLAGS) -L$(MLX_DIR) -l$(MLX_NAME) \
		-L$(GNL_DIR) -l$(GNL_NAME) \
		-framework OpenGL -framework AppKit -g $^ -o $@

%.o : %.c
	$(CC) $(CFLAGS) -I$(MLX_DIR) -I$(GNL_DIR) -c $< -o $@

clean:
	rm -rf $(OBJS) $(OJBSB)
	make -C $(MLX_DIR) clean
	make -C $(GNL_DIR) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(MLX_DIR) clean
	make -C $(GNL_DIR) fclean

re: fclean all

bonus: 
	make WITH_BONUS=1 all

.PHONY: all clean fclean re bonus
