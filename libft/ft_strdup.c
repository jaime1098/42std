/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 04:39:45 by joltra-r          #+#    #+#             */
/*   Updated: 2023/09/24 16:00:05 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dup;
	size_t	length;

	length = ft_strlen(s) + 1;
	i = 0;
	dup = malloc(length);
	if (!dup)
		return (NULL);
	while (i < (int)length)
	{
		dup[i] = s[i];
		i++;
	}
	return (dup);
}
/*
int main()
{
    const char *original = "Hola, mundo!";
    char *copia = strdup(original);

    if (copia != NULL) {
        printf("Copia: %s\n", copia);
        free(copia); // Liberar la memoria cuando ya no se necesite
    } else {
        printf("La asignación de memoria falló.\n");
    }

    return 0;
}*/
