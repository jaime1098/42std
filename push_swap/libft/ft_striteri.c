/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:07:21 by joltra-r          #+#    #+#             */
/*   Updated: 2023/10/03 12:07:23 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (s == '\0' || f == '\0')
		return ((void) NULL);
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
/*
#include <stdio.h>

// Función que agrega un número al valor de cada carácter en la cadena
void addNumber(unsigned int index, char *c)
{
    int number = index + 1; // El índice comienza en 0, por lo que sumamos 1
    *c += number; // Modificamos el carácter en la dirección apuntada por 'c'
}

int main()
{
    char cadena[] = "abcde";

    // Aplicar addNumber a cada carácter de la cadena
    ft_striteri(cadena, addNumber);

    printf("Cadena modificada: %s\n", cadena);

    return 0;
}*/
