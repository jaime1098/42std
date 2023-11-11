#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include "libft.h"

int	ft_printf(char const *text, ...);
int ft_isc(va_list args);
int ft_iss(va_list args);
int ft_isp(va_list args);
int ft_isid(va_list args);
int ft_isu(va_list args);
int ft_isxX(va_list args, const char *text);
int ft_returns(const char *text, va_list args, int n);
int main();

#endif