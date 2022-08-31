make re
gcc ft_printf.o main.c -I.ft_printf.h -L. libftprintf.a -o a.out
./a.out | cat -e