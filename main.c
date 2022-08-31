#include "stdio.h"
#include "ft_printf.h"
#include <limits.h>

int main()
{
    ft_printf("ft_printf no format test: hello world\n");
    printf("printf no format test: hello world\n");

    ft_printf("ft_printf percent: %%\n");
    printf("printf percent: %%\n");

    ft_printf("ft_printf char test : %c\n", 'c');
    printf("printf char test : %c\n", 'c');

    ft_printf("ft_printf char with 0 : %010c\n", 'c');
    printf("printf char with 0 : %010c\n", 'c');

    ft_printf("ft_printf char with - : %-10c\n", 'c');
    printf("printf char with - : %-10c\n", 'c');

    ft_printf("ft_printf char with width : %10c\n", 'c');
    printf("printf char with width : %10c\n", 'c');

    ft_printf("ft_printf string test : %s\n", "hello world");
    printf("printf string test : %s\n", "hello world");

    ft_printf("ft_printf string null test : %s\n", 0);
    printf("printf string null test : %s\n", 0);

    ft_printf("ft_printf string with 0 : %020s\n", "hello world");
    printf("printf string with 0 : %020s\n", "hello world");

    ft_printf("ft_printf string with - : %-20s\n", "hello world");
    printf("printf string with - : %-20s\n", "hello world");

    ft_printf("ft_printf string with width : %20s\n", "hello world");
    printf("printf string with width : %20s\n", "hello world");

    ft_printf("ft_printf string with precision : %20.3s\n", "hello world");
    printf("printf string with precision : %20.3s\n", "hello world");

    ft_printf("ft_printf string with long precision : %20.30s\n", "hello world");
    printf("printf string with long precision : %20.30s\n", "hello world");

    ft_printf("ft_printf integer test : %i\n", INT_MIN);
    printf("printf integer test : %i\n", INT_MIN);

    ft_printf("ft_printf integer with plus : %+i\n", INT_MAX);
    printf("printf integer with plus : %+i\n", INT_MAX);

    ft_printf("ft_printf integer with space : % i\n", INT_MAX);
    printf("printf integer with space : % i\n", INT_MAX);

    ft_printf("ft_printf integer with 0 plus : %+020i\n", INT_MIN);
    printf("printf integer with 0 plus : %+020i\n", INT_MIN);

    ft_printf("ft_printf integer with 0 plus precision : %+020.15i\n", INT_MIN);
    printf("printf integer with 0 plus precision : %+020.15i\n", INT_MIN);

    ft_printf("ft_printf integer with 0 plus zero precision : %+020.i\n", INT_MIN);
    printf("printf integer with 0 plus zero precision : %+020.i\n", INT_MIN);

    ft_printf("ft_printf integer with 0 space : % 020i\n", INT_MIN);
    printf("printf integer with 0 space : % 020i\n", INT_MIN);

    ft_printf("ft_printf integer with 0 space precision : % 020.15i\n", INT_MIN);
    printf("printf integer with 0 space precision : % 020.15i\n", INT_MIN);

    ft_printf("ft_printf integer with 0 space zero precision : % 020.i\n", INT_MIN);
    printf("printf integer with 0 space zero precision : % 020.i\n", INT_MIN);

    ft_printf("ft_printf integer with plus : %+20i\n", INT_MIN);
    printf("printf integer with plus : %+20i\n", INT_MIN);

    ft_printf("ft_printf integer with plus precision : %+20.15i\n", INT_MIN);
    printf("printf integer with plus precision : %+20.15i\n", INT_MIN);

    ft_printf("ft_printf integer with plus zero precision : %+20.i\n", INT_MIN);
    printf("printf integer with plus zero precision : %+20.i\n", INT_MIN);

    ft_printf("ft_printf integer with space : % 20i\n", INT_MIN);
    printf("printf integer with space : % 20i\n", INT_MIN);

    ft_printf("ft_printf integer with space precision : % 20.15i\n", INT_MIN);
    printf("printf integer with space precision : % 20.15i\n", INT_MIN);

    ft_printf("ft_printf integer with space zero precision : % 20.i\n", INT_MIN);
    printf("printf integer with space zero precision : % 20.i\n", INT_MIN);

    ft_printf("ft_printf decimal test : %d\n", INT_MIN);
    printf("printf decimal test : %d\n", INT_MIN);

    ft_printf("ft_printf decimal with plus : %+d\n", INT_MAX);
    printf("printf decimal with plus : %+d\n", INT_MAX);

    ft_printf("ft_printf decimal with space : % d\n", INT_MAX);
    printf("printf decimal with space : % d\n", INT_MAX);

    ft_printf("ft_printf decimal with 0 plus : %+020d\n", INT_MIN);
    printf("printf decimal with 0 plus : %+020d\n", INT_MIN);

    ft_printf("ft_printf decimal with 0 plus precision : %+020.15d\n", INT_MIN);
    printf("printf decimal with 0 plus precision : %+020.15d\n", INT_MIN);

    ft_printf("ft_printf decimal with 0 plus zero precision : %+020.d\n", INT_MIN);
    printf("printf decimal with 0 plus zero precision : %+020.d\n", INT_MIN);

    ft_printf("ft_printf decimal with 0 space : % 020d\n", INT_MIN);
    printf("printf decimal with 0 space : % 020d\n", INT_MIN);

    ft_printf("ft_printf decimal with 0 space precision : % 020.15d\n", INT_MIN);
    printf("printf decimal with 0 space precision : % 020.15d\n", INT_MIN);

    ft_printf("ft_printf decimal with 0 space zero precision : % 020.d\n", INT_MIN);
    printf("printf decimal with 0 space zero precision : % 020.d\n", INT_MIN);

    ft_printf("ft_printf decimal with plus : %+20d\n", INT_MIN);
    printf("printf decimal with plus : %+20d\n", INT_MIN);

    ft_printf("ft_printf decimal with plus precision : %+20.15d\n", INT_MIN);
    printf("printf decimal with plus precision : %+20.15d\n", INT_MIN);

    ft_printf("ft_printf decimal with plus zero precision : %+20.d\n", INT_MIN);
    printf("printf decimal with plus zero precision : %+20.d\n", INT_MIN);

    ft_printf("ft_printf decimal with space : % 20d\n", INT_MIN);
    printf("printf decimal with space : % 20d\n", INT_MIN);

    ft_printf("ft_printf decimal with space precision : % 20.15d\n", INT_MIN);
    printf("printf decimal with space precision : % 20.15d\n", INT_MIN);

    ft_printf("ft_printf decimal with space zero precision : % 20.d\n", INT_MIN);
    printf("printf decimal with space zero precision : % 20.d\n", INT_MIN);

    ft_printf("ft_printf unsigned int test : %u\n", INT_MAX);
    printf("printf unsigned int test : %u\n", INT_MAX);

    ft_printf("ft_printf unsigned int with width : %20u\n", INT_MAX);
    printf("printf unsigned int with width : %20u\n", INT_MAX);

    ft_printf("ft_printf unsigned int with width precision : %20.3u\n", INT_MAX);
    printf("printf unsigned int with width precision : %20.3u\n", INT_MAX);

    ft_printf("ft_printf unsigned int with 0 : %020u\n", INT_MAX);
    printf("printf unsigned int with 0 : %020u\n", INT_MAX);

    ft_printf("ft_printf unsigned int with - : %-20u\n", INT_MAX);
    printf("printf unsigned int with - : %-20u\n", INT_MAX);

    ft_printf("ft_printf hex test : %x %X\n", LONG_MAX, LONG_MAX);
    printf("printf hex test : %x %X\n", LONG_MAX, LONG_MAX);

    ft_printf("ft_printf hex with width : %20x %20X\n", LONG_MAX, LONG_MAX);
    printf("printf hex with width : %20x %20X\n", LONG_MAX, LONG_MAX);

    ft_printf("ft_printf hex with width precision : %20.3x %20.3X\n", LONG_MAX, LONG_MAX);
    printf("printf hex with width precision : %20.3x %20.3X\n", LONG_MAX, LONG_MAX);

    ft_printf("ft_printf hex with witdh zero precision : %20.x %20.X\n", LONG_MAX, LONG_MAX);
    printf("printf hex with witdh zero precision : %20.x %20.X\n", LONG_MAX, LONG_MAX);

    ft_printf("ft_printf hex with 0 : %020x %020X\n", LONG_MAX, LONG_MAX);
    printf("printf hex with 0 : %020x %020X\n", LONG_MAX, LONG_MAX);

    ft_printf("ft_printf hex with - : %-20x %-20X\n", LONG_MAX, LONG_MAX);
    printf("printf hex with - : %-20x %-20X\n", LONG_MAX, LONG_MAX);

    ft_printf("ft_printf hex with # : %#20x %#20X\n", LONG_MAX, LONG_MAX);
    printf("printf hex with # : %#20x %#20X\n", LONG_MAX, LONG_MAX);

    ft_printf("ft_printf hex with 0 # : %#020x %#020X\n", LONG_MAX, LONG_MAX);
    printf("printf hex with 0 # : %#020x %#020X\n", LONG_MAX, LONG_MAX);

    ft_printf("ft_printf hex with - # : %#-20x %#-20X\n", LONG_MAX, LONG_MAX);
    printf("printf hex with - # : %#-20x %#-20X\n", LONG_MAX, LONG_MAX);

    ft_printf("ft_printf hex with 0 # precison : %#020.5x %#020.5X\n", LONG_MAX, LONG_MAX);
    printf("printf hex with 0 # precison : %#020.5x %#020.5X\n", LONG_MAX, LONG_MAX);

    ft_printf("ft_printf hex with 0 # zero precision : %#020.x %#020.X\n", LONG_MAX, LONG_MAX);
    printf("printf hex with 0 # zero precision : %#020.x %#020.X\n", LONG_MAX, LONG_MAX);

    ft_printf("ft_printf hex with - # zero precision : %#-20.x %#-20.X\n", LONG_MAX, LONG_MAX);
    printf("printf hex with - # zero precision : %#-20.x %#-20.X\n", LONG_MAX, LONG_MAX);

    ft_printf("ft_printf pointer test : %p\n", ULONG_MAX);
    printf("printf pointer test : %p\n", ULONG_MAX);

    ft_printf("ft_printf pointer with width : %20p\n", ULONG_MAX);
    printf("printf pointer with width : %20p\n", ULONG_MAX);

    ft_printf("ft_printf pointer - : %-20p\n", ULONG_MAX);
    printf("printf pointer - : %-20p\n", ULONG_MAX);

    ft_printf("ft_printf pointer width precision 0 : %020.10p\n", ULONG_MAX);
    printf("printf pointer width precision 0 : %020.10p\n", ULONG_MAX);

    ft_printf("ft_printf pointer width precision 0 : %-20.10p\n", ULONG_MAX);
    printf("printf pointer width precision 0 : %-20.10p\n", ULONG_MAX);

    ft_printf("ft_printf pointer 0 : %020p\n", ULONG_MAX);
    printf("printf pointer 0 : %020p\n", ULONG_MAX);
}
    