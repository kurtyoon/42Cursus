NAME = push_swap
LIBFT = libft
LIBFT_LIB = libft.a

SRCS = src/main.c src/order_utils.c src/order.c src/stack_concurrent.c src/stack_operation.c src/stack_utils.c src/stack.c
OBJS = $(SRCS:.c=.o)
INCS = inc
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $< -I$(INCS)

$(NAME): $(OBJS)
	make bonus -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT)/$(LIBFT_LIB) -o $@

all: $(NAME)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT)

clean:
	$(RM) $(OBJS)
	make clean -C $(LIBFT))

re: fclean all

.PHONY: all clean fclean re