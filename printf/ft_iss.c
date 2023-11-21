/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iss.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:10:52 by joltra-r          #+#    #+#             */
/*   Updated: 2023/11/16 13:10:53 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int	ft_iss(va_list args)
{
	char	*s;

	s = va_arg(args, char *);
	if (s == (char *) NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
		ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}
