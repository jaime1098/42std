/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isxX.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:11:15 by joltra-r          #+#    #+#             */
/*   Updated: 2023/11/16 13:11:16 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

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

int	ft_decimaltohexadecimalupper(unsigned int decimal)
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
			hexadecimal[i] = aux + 'A' - 10;
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

int	ft_isx(va_list args, const char *text)
{
	unsigned int	n;
	int				hexa;

	n = va_arg(args, unsigned int);
	if (n == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	if (*text == 'x')
	{
		hexa = ft_decimaltohexadecimallower(n);
		return (hexa);
	}
	else
	{
		hexa = ft_decimaltohexadecimalupper(n);
		return (hexa);
	}
}
