/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isu.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:11:01 by joltra-r          #+#    #+#             */
/*   Updated: 2023/11/16 13:11:03 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int	ft_isu(va_list args)
{
	unsigned int	n;
	char			*itoa;

	n = va_arg (args, unsigned int);
	ft_putunbr_fd((unsigned int)n, 1);
	itoa = ft_unsigneditoa(n);
	n = ft_strlen(itoa);
	free (itoa);
	return (n);
}
