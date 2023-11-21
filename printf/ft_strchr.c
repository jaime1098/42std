/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:52:01 by joltra-r          #+#    #+#             */
/*   Updated: 2023/09/19 11:52:03 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strchr(const char *str, int c)
{
	unsigned char	ch;

	ch = (unsigned char)c;
	while (*str != ch && *str != '\0')
		str++;
	if (*str == ch)
		return ((char *)str);
	else
		return (NULL);
}

#if 0

int	main(void)
{
	char	*resultado;

	resultado = ft_strchr("Hello", 'H');
	if (resultado != NULL)
		printf("El ch '%c' esta en pos %ld.\n", 'H', resultado - "Hello");
	else
		printf("El ch '%c' no esta en el str.\n", 'H');
	return (0);
}
#endif
