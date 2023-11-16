/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:29:40 by joltra-r          #+#    #+#             */
/*   Updated: 2023/11/11 19:29:42 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "libftprintf.h"

int	ft_isid(va_list args)
{
	int		n;
	char	*itoa;

	n = va_arg(args, int);
	ft_putnbr_fd(n, 1);
	itoa = ft_itoa(n);
	return (ft_strlen(itoa));
}
