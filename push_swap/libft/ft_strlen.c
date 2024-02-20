/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 12:50:00 by joltra-r          #+#    #+#             */
/*   Updated: 2023/09/16 13:46:52 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
/*
int main()
{
char *str = "Hello World";
int length = strlen(str);
int longitud = ft_strlen(NULL);
printf("Length is: %i\n", length);
printf("Longitud es: %i\n", longitud);
return 0;
}*/
