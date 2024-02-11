/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 04:49:38 by joltra-r          #+#    #+#             */
/*   Updated: 2023/09/24 16:01:02 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*completestr(char const *s1, char const *s2, char *cstr, size_t l)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < (int)l - 1)
	{
		while (s1[i] != '\0')
		{
			cstr[i] = s1[i];
			i++;
		}
		while (s2[j] != '\0')
		{
			cstr[i] = s2[j];
			j++;
			i++;
		}
	}
	cstr[i] = '\0';
	return (cstr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strcomplete;
	size_t	length;
	char	*result;

	length = ft_strlen(s1) + ft_strlen(s2) + 1;
	strcomplete = malloc(length);
	if (strcomplete == NULL)
		return (NULL);
	result = completestr(s1, s2, strcomplete, length);
	return (result);
}

/*int main() 
{
	char *resultft = ft_strjoin("Hola", "Mundo");
	printf("Subcadena: %s\n", resultft);
	free (resultft);

	return 0;
}*/
