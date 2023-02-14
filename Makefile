CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
NAME = push_swap
CHECKER = checker

SRCS = 	mandatory/main.c \
		mandatory/parse.c \
		mandatory/greedy.c \
		mandatory/stack_concurrent.c \
		mandatory/stack_operation.c \
		mandatory/utils.c \
		mandatory/sort.c

SRCSB =	bonus/checker.c \
		bonus/stack_concurrent.c \
		bonus/stack_operation.c \
		bonus/commands.c \
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

bonus: $(CHECKER)

$(CHECKER): $(OBJSB)
	make -C $(PRINTF_DIR) all
	make -C $(GNL_DIR) all
	$(CC) $(CFLAGS) -L$(PRINTF_DIR) -l$(PRINTF_NAME) \
		 -L$(GNL_DIR) -l$(GNL_NAME) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -I$(PRINTF_DIR) -I$(GNL_DIR) -c $< -o $@

clean:
	$(RM) $(OBJS) $(OBJSB)
	make -C $(GNL_DIR) fclean
	make -C $(PRINTF_DIR) fclean

fclean: clean
	$(RM) $(NAME) $(CHECKER)
	make -C $(GNL_DIR) fclean
	make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re