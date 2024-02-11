/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:59:10 by joltra-r          #+#    #+#             */
/*   Updated: 2023/10/22 19:52:04 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strrchr(const char *str, int c)
{
	const char	*aux;

	aux = str;
	while (*str != '\0')
		str++;
	while (str >= aux)
	{
		if (*str == (unsigned char)c)
			return ((char *)str);
		str--;
	}
	return (NULL);
}

/*int	main(void)
{
	char *resultado = ft_strrchr("teste", 'e');
	printf("%s", resultado);
	if (resultado != NULL)
printf("El ch '%c' esta en la pos %ld del str.\n", c, resultado - str);
	else
printf("El ch '%c' no esta en el str.\n", c);
	return 0;
}*/
