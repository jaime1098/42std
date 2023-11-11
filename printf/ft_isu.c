#include <stdarg.h>
#include "libft.h"
#include "libftprintf.h"

int ft_isu(va_list args)
{
	unsigned int n;
	char *itoa;

	n = va_arg(args, unsigned int);
	ft_putunsignednbr_fd(n, 1);
	itoa = ft_itoa(n)
	return (ft_strlen(itoa));
}

void    ft_putunsignednbr_fd(unsigned int nb, int fd)
{
    char    a;

    if (nb >= 10)
    {
        ft_putunsignednbr_fd(nb / 10, fd);
    }
    if (nb)
    {
        a = nb % 10 + '0';
        write(fd, &a, 1);
    }
}