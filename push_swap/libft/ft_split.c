/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 00:20:07 by joltra-r          #+#    #+#             */
/*   Updated: 2023/10/02 00:20:09 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_numwords(char const *s, char c)
{
	int	words;
	int	aux;

	words = 0;
	aux = 0;
	while (*s != '\0')
	{
		if (*s == c)
			aux = 0;
		else if (aux == 0)
		{
			aux = 1;
			words++;
		}
		s++;
	}
	return (words);
}

char	*ft_createwords(char const *s, char c)
{
	int		i;
	char	*word;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	word = malloc(i + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_result(char **result, const char *s, char c, int i)
{
	result[i] = ft_createwords(s, c);
	if (result[i] == NULL)
	{
		while (i >= 0)
		{
			free(result[i]);
			i --;
		}
		free(result);
		return (NULL);
	}
	return (result);
}

char	**ft_split(char const *s, char c)
{
	int		num_words;
	char	**result;
	int		i;

	num_words = ft_numwords(s, c);
	result = (char **)malloc((num_words + 1) * sizeof(char *));
	i = 0;
	if (!result)
		return (NULL);
	while (*s != '\0')
	{
		if (*s == c)
			s++;
		else
		{
			result = ft_result(result, s, c, i);
			if (result == NULL)
				return (NULL);
			while (*s != '\0' && *s != c)
				s++;
			i++;
		}
	}
	result[i] = NULL;
	return (result);
}
/*
int main()
{
	char const *cadena = "Hola,mundo,cruel";
	char **subcadenas = ft_split(cadena, ',');
	if (subcadenas != NULL)
	{
		int i = 0;
    	while (subcadenas[i] != NULL)
    	{
    	    printf("Subcadena %d: %s\n", i, subcadenas[i]);
    	    free(subcadenas[i]);
    	    i++;
    	}
    	free(subcadenas);
	}
	return (0);
}*/