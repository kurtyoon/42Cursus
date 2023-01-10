CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

SRCS =	mandatory/ft_printf.c mandatory/ft_format.c \
		mandatory/ft_parse.c mandatory/ft_print_chars.c \
		mandatory/ft_print_hex.c mandatory/ft_print_nbrs.c \
		mandatory/ft_print_point.c mandatory/ft_print_utils.c
OBJS = $(SRCS:.c=.o)
INCS = include

LIBFT = include/libft
LIBFT_LIB = libft.a

all: $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIBFT) bonus
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	ar rc $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCS)

clean:
	rm -rf $(OBJS)
	make -C $(LIBFT) clean


fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT) fclean

re: fclean all

bonus: $(NAME)

.PHONY: all clean fclean re bonus
