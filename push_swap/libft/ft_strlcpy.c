/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 12:50:00 by joltra-r          #+#    #+#             */
/*   Updated: 2023/11/14 12:09:21 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t strl)
{
	size_t	i;

	i = 0;
	while (strl > 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
		strl--;
	}
	if (strl > 0)
		dst[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}

/*int	main(void)
{
	char	src[20] = "Holaaaa";
	char	dest[20] = "Mundo";
	char	dest2[20] = "Mundo";


	printf("Original: %lu, %s\n", strlcpy(dest, src, 4), dest);
	printf("My function: %lu, %s", ft_strlcpy(dest2, src, 4), dest2);
	return (0);
}*/
