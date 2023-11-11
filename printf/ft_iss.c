#include <stdarg.h>
#include "libft.h"
#include "libftprintf.h"

int ft_iss(va_list args)	
{
	char *s;
		
	s = va_arg(args, char *);
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}