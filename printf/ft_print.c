#include <stdarg.h>
#include "libft.h"
#include "libftprintf.h"

int ft_flags(const char *text, va_list args)
{
	int n;
	text++;
	if (*text == 'c')
		ft_isc(args);
if (*text == 's')
		ft_iss(args);
	if (*text == 'p')
		ft_isp(args);
	if (*text == 'i' || *text == 'd')
		ft_isid(args);
	if (*text == 'u')
		ft_isu(args);
	if (*text == 'x' || *text == 'X')
		n = ft_isxX(args);
	if (*text == '%')
		ft_putchar_fd('%', 1);
	return (ft_returns(text, args, n));
}

int ft_printf(const char *text, ...)
{
	int char_count;

	char_count = 0;
	va_list args;
	va_start(args, text);
	while (*text != '\0')
	{
		if (*text != '%')
		{
			ft_putchar_fd(*text, 1);
			text++;
			char_count++;
		}
		else if (ft_strchr("cspdiuxX%", *(text + 1)))
		{
		char_count += ft_flags(text, args);
		text += 2;
		}
		else
		{
			ft_putchar_fd(*text, 1);
			text++;
			char_count++;
		}
	}
	return (char_count);
}