/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 00:01:25 by joltra-r          #+#    #+#             */
/*   Updated: 2023/10/02 00:01:27 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_createword(const char *s1, int auxi, int i, int j)
{
	int		cont;
	char	*trim;

	trim = (char *)malloc((i - auxi + 1) + 1);
	if (!trim)
		return (NULL);
	cont = 0;
	j = auxi;
	while (cont < (i - auxi + 1) + 1)
	{
		trim[cont] = s1[j];
		cont++;
		j++;
	}
	trim[cont - 1] = '\0';
	return (trim);
}

int	ft_needi(char const *s1, char const *set)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (set[j] != '\0')
	{
		while (s1[i] == set[j])
		{
			j = 0;
			i++;
		}
		j++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		auxi;
	char	*trim;

	auxi = ft_needi(s1, set);
	i = ft_strlen(s1) - 1;
	j = ft_strlen(set) - 1;
	while (j >= 0)
	{
		while (s1[i] == set[j])
		{
			if (i == 0)
				return (ft_strdup(""));
			j = ft_strlen(set) - 1;
			i--;
		}
		j--;
	}
	trim = ft_createword(s1, auxi, i, j);
	return (trim);
}

/*int main()
{
	char s1[] = "          ";
	char *result = ft_strtrim(s1, " ");
	printf ("Resultado: %s\n", result);
	free (result);
	return 0;
}*/
