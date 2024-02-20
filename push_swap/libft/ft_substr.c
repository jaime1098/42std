/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:57:16 by joltra-r          #+#    #+#             */
/*   Updated: 2023/11/14 12:31:09 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(const char *str, unsigned int start, size_t length)
{
	int		i;
	char	*sub;
	size_t	longitud;

	longitud = ft_strlen(str);
	i = 0;
	if (start >= longitud)
		return (ft_strdup(""));
	if (length > longitud - start)
		length = longitud - start;
	sub = malloc(length + 1);
	if (!sub)
		return (NULL);
	while (i < (int)length)
	{
		sub[i] = str[start];
		start++;
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

/*int main() 
{
	char *result = ft_substr("Hola", 2, 5);
	
	printf("Subcadena: %s\n", result);
	free (result);

	return 0;
}*/
