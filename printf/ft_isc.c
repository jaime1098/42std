/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:29:40 by joltra-r          #+#    #+#             */
/*   Updated: 2023/11/11 19:29:42 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libftprintf.h"

int	ft_isc(va_list args)
{
	char	c;
	int n;

	c = (char)va_arg(args, int);
	ft_putchar_fd(c, 1);
	n = 1;
	return (n);
}
