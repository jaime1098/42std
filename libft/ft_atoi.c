/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 04:34:55 by joltra-r          #+#    #+#             */
/*   Updated: 2023/09/24 15:49:43 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(const char *numchar)
{
	int	n;
	int	i;
	int	aux;

	n = 0;
	i = 0;
	aux = 1;
	while ((numchar[i] >= 9 && numchar[i] <= 13) || numchar[i] == 32)
		i++;
	if (numchar[i] == '-' || numchar[i] == '+')
	{
		if (numchar[i] == '-')
			aux = -1;
		i++;
	}
	while (numchar[i] >= '0' && numchar[i] <= '9')
	{
		n = n * 10 + numchar[i] - '0';
		i++;
	}
	n = n * aux;
	return (n);
}
/*
int main() {
	const char *str = "-+12345xd";
	int num = ft_atoi(str);
	const char *str2 = "-+12345xd";
	int num2 = atoi(str2);
	printf("El número es: %d\n", num);
	printf("El número es: %d\n", num2);
	return 0;
}*/
