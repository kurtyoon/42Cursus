NAME = libftprintf.a
LIBFT  libft

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I
AR = ar
ARFLAGS = rcs
RM = rm -f

SRCS = ft_printf.c \
	   ft_print_func.c \
	   ft_print_hex.c \
	   ft_print_ptr.c \
	   ft_print_unsigned.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $<

$(NAME) : $(OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a .
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

all: $(NAME)

clean:
	make clean -C $(LIBFT)
	$(RM) $(OBJS)

fclean: clean
	make fclean -C $(LIBFT)
	$(RM) $(NAME)

re: fclean all

bonus: 

.PHONY: all clean fclean re bonus
