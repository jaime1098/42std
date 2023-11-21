/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:11:27 by joltra-r          #+#    #+#             */
/*   Updated: 2023/11/16 13:11:28 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libftprintf.h"

int	ft_flags(const char *text, va_list args)
{
	int	n;

	text++;
	n = 0;
	if (*text == 'c')
		ft_isc(args);
	else if (*text == 's')
		ft_iss(args);
	else if (*text == 'p')
		ft_isp(args);
	else if (*text == 'i' || *text == 'd')
		ft_isid(args);
	else if (*text == 'u')
		ft_isu(args);
	else if (*text == 'x' || *text == 'X')
		n = ft_isx(args, text);
	else
		ft_putchar_fd('%', 1);
	return (ft_returns(text, args, n));
}

int	ft_printf(const char *text, ...)
{
	int		char_count;
	va_list	args;

	char_count = 0;
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
