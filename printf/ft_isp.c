/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:29:40 by joltra-r          #+#    #+#             */
/*   Updated: 2023/11/11 19:29:42 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libftprintf.h"

int	ft_decimaltohexadecimallower(unsigned int decimal)
{
	char	hexadecimal[20];
	int		i;
	int		aux;

	i = 0;
	while (decimal != 0)
	{
		aux = decimal % 16;
		if (aux < 10)
		hexadecimal[i] = aux + '0';
		else
		hexadecimal[i] = aux + 'a' - 10;
	i++;
	decimal /= 16;
	}
	aux = i;
	i -= 1;
	while (i >= 0)
	{
		ft_putchar_fd (hexadecimal[i], 1);
		i--;
	}
	return (aux);
}
int	ft_isp(va_list args)
{
	void	*p;
	int n;

	p = va_arg(args, void *);
	ft_putstr_fd("0x", 1);
	n = ft_decimaltohexadecimallower((unsigned int)p);
	return (n);
	}
