CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
NAME = push_swap

SRCS = 	mandatory/main.c \
		mandatory/order_utils.c \
		mandatory/order.c \
		mandatory/stack_concurrent.c \
		mandatory/stack_operation.c \
		mandatory/stack_utils.c \
		mandatory/stack.c
OBJS = $(SRCS:.c=.o)
INCS = include

GNL_NAME = gnl
GNL_DIR = ./include/get_next_line
PRINTF_NAME = ftprintf
PRINTF_DIR = ./include/ft_printf

all: $(NAME)

.c.o: $(OBJS)
	$(CC) $(CFLAGS) -c -o $@ $< -I$(INCS)

$(NAME): $(OBJS)
	make -C $(PRINTF_DIR) all
	make -C $(GNL_DIR) all
	$(CC) $(CFLAGS) -L$(PRINTF_DIR) -l$(PRINTF_NAME) \
		 -L$(GNL_DIR) -l$(GNL_NAME) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -I$(PRINTF_DIR) -I$(GNL_DIR) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make -C $(GNL_DIR) clean
	make -C $(PRINTF_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(GNL_DIR) fclean
	make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re