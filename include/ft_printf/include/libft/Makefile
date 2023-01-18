CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

RM = rm -f

AR = ar
ARFLAGS = crs

INCS = include

SRCS_NM = mandatory/ft_isalpha.c \
		  mandatory/ft_isdigit.c \
		  mandatory/ft_isalnum.c \
		  mandatory/ft_isascii.c \
		  mandatory/ft_isprint.c \
		  mandatory/ft_isspace.c \
		  mandatory/ft_strlen.c \
		  mandatory/ft_memset.c \
		  mandatory/ft_bzero.c \
		  mandatory/ft_memcpy.c \
		  mandatory/ft_memmove.c \
		  mandatory/ft_strlcpy.c \
		  mandatory/ft_strlcat.c \
		  mandatory/ft_strncmp.c \
		  mandatory/ft_toupper.c \
		  mandatory/ft_tolower.c \
		  mandatory/ft_strchr.c \
		  mandatory/ft_strrchr.c \
		  mandatory/ft_memchr.c \
		  mandatory/ft_memcmp.c \
		  mandatory/ft_strnstr.c \
		  mandatory/ft_atoi.c \
		  mandatory/ft_calloc.c \
		  mandatory/ft_strdup.c \
		  mandatory/ft_substr.c \
		  mandatory/ft_strjoin.c \
		  mandatory/ft_strtrim.c \
		  mandatory/ft_split.c \
		  mandatory/ft_itoa.c \
		  mandatory/ft_strmapi.c \
		  mandatory/ft_striteri.c \
		  mandatory/ft_putchar_fd.c \
		  mandatory/ft_putnchar_fd.c \
		  mandatory/ft_putnbr_base_fd.c \
		  mandatory/ft_putstr_fd.c \
		  mandatory/ft_putendl_fd.c \
		  mandatory/ft_putnbr_fd.c \
		  mandatory/ft_isspace.c \
		  mandatory/ft_nbrlen.c \
		  mandatory/ft_swap.c \
		  mandatory/ft_min.c \
		  mandatory/ft_max.c \
		  mandatory/ft_abs.c \
		  mandatory/ft_strcmp.c

SRCS_BN = bonus/ft_lstnew.c \
		  bonus/ft_lstadd_front.c \
		  bonus/ft_lstsize.c \
		  bonus/ft_lstlast.c \
		  bonus/ft_lstadd_back.c \
		  bonus/ft_lstdelone.c \
		  bonus/ft_lstclear.c \
		  bonus/ft_lstiter.c \
		  bonus/ft_lstmap.c

OBJS = $(SRCS_NM:.c=.o)

OBJS_BONUS = $(SRCS_BN:.c=.o)

ifdef WITH_BONUS
		OBJ_FILES = $(OBJS) $(OBJS_BONUS)
	else
		OBJ_FILES = $(OBJS)
endif

all : $(NAME)

.c.o : $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $< -I$(INCS)

$(NAME) : $(OBJ_FILES)
	$(AR) $(ARFLAGS) $@ $^

clean :
	$(RM) $(RMFLAG) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(RMFLAG) $(NAME)

re: fclean all

bonus:
		@make WITH_BONUS=1 all

.PHONY : all clean fclean re bonus
