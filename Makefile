CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
NAME = push_swap
CHECKER = checker

SRCS = 	mandatory/main.c \
		mandatory/parse.c \
		mandatory/order.c \
		mandatory/deque_concurrent.c \
		mandatory/deque_operation.c \
		mandatory/deque_utils.c \
		mandatory/deque.c

SRCSB =	bonus/checker.c \
		bonus/deque.c \
		bonus/deque_concurrent.c \
		bonus/deque_operation.c \
		bonus/parse_utils.c \
		bonus/parse.c

OBJS = $(SRCS:.c=.o)
OBJSB = $(SRCSB:.c=.o)
INCS = include

GNL_NAME = gnl
GNL_DIR = ./include/get_next_line
PRINTF_NAME = ftprintf
PRINTF_DIR = ./include/ft_printf

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(PRINTF_DIR) all
	make -C $(GNL_DIR) all
	$(CC) $(CFLAGS) -L$(PRINTF_DIR) -l$(PRINTF_NAME) \
		 -L$(GNL_DIR) -l$(GNL_NAME) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -I$(PRINTF_DIR) -I$(GNL_DIR) -c $< -o $@

bonus: $(NAME) $(CHECKER)

$(NAME): $(OBJS)
	make -C $(PRINTF_DIR) all
	make -C $(GNL_DIR) all
	$(CC) $(CFLAGS) -L$(PRINTF_DIR) -l$(PRINTF_NAME) \
		 -L$(GNL_DIR) -l$(GNL_NAME) $^ -o $@

$(CHECKER): $(OBJSB)
	$(CC) $(CFLAGS) -L$(PRINTF_DIR) -l$(PRINTF_NAME) \
		 -L$(GNL_DIR) -l$(GNL_NAME) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -I$(PRINTF_DIR) -I$(GNL_DIR) -c $< -o $@

clean:
	$(RM) $(OBJS) $(OBJSB)
	make -C $(GNL_DIR) clean
	make -C $(PRINTF_DIR) clean

fclean: clean
	$(RM) $(NAME) $(CHECKER)
	make -C $(GNL_DIR) fclean
	make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re