/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 19:56:26 by joltra-r          #+#    #+#             */
/*   Updated: 2023/11/14 12:13:49 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t strl)
{
	size_t	sdest;
	size_t	ssrc;
	size_t	total;
	int		i;

	i = 0;
	sdest = ft_strlen(dst);
	ssrc = ft_strlen(src);
	if (strl <= sdest)
		total = strl + ssrc;
	else
		total = ssrc + sdest;
	while (src[i] != '\0' && sdest + 1 < strl)
	{
		dst[sdest] = src[i];
		i++;
		sdest++;
	}
	dst[sdest] = '\0';
	return (total);
}

/*int	main(void)
{
	char		destino[10] = "a";
    const char	*origen = "ll";
	size_t		longitud;

	longitud = ft_strlcat(destino, origen, 7);
	printf ("dest ft: %s\n", destino);
	printf ("strl ft: %zu\n", longitud);
	return (0);
}*/
