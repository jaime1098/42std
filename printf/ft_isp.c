#include <stdarg.h>
#include "libft.h"
#include "libftprintf.h"

int ft_isp(va_list args)
{
        void *p;

				p = va_arg(args, void *);
        char *str = ft_itoa_base((unsigned long)p, 16);
        ft_putstr_fd("0x", 1);
        ft_putstr_fd(str, 1);
    }

char *ft_itoa_base(unsigned long n, int base)
{
    static char *base_chars = "0123456789abcdef";
    static char buffer[50];
    char *p = buffer + sizeof(buffer) - 1;
    *p = '\0';
    do {
        *--p = base_chars[n % base];
        n /= base;
    } while (n != 0);
    return p;
}