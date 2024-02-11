/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:58:19 by joltra-r          #+#    #+#             */
/*   Updated: 2023/10/03 11:58:20 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

/*char toUpperCase(unsigned int index, char c)
{
	if (c >= 'a' && c <= 'z')
		return c + 32;
	return c;
}*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	int		i;
	char	*result;

	len = ft_strlen(s);
	result = (char *)malloc(len + 1);
	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	if (result == NULL)
		return (NULL);
	while (i < (int)len)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[len] = '\0';
	return (result);
}
/*
int main()
{
	const char *cadena = "Hola, mundo!";
	char *resultado = ft_strmapi(cadena, toUpperCase);

	if (resultado != NULL)
	{
		printf("Resultado: %s\\n", resultado);
		free(resultado); // No olvides liberar la memoria cuando termines
	}
	else
		printf("Error al crear la nueva cadena.\\n")
	return (0);
}*/
