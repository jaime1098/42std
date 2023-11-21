/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_returns.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:11:42 by joltra-r          #+#    #+#             */
/*   Updated: 2023/11/16 13:11:43 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libftprintf.h"

int	ft_returns(const char *text, va_list args, int n)
{
	if (*text == 'c')
		return (ft_strlen(args));
	if (*text == 's')
		return (ft_strlen(args));
	if (*text == 'p')
		ft_isp(args);
	if (*text == 'i' || *text == 'd')
		return (ft_strlen(args));
	if (*text == 'u')
		return (ft_strlen(args));
	if (*text == 'x' || *text == 'X')
		return (n);
	if (*text == '%')
		return (1);
	return (0);
}
