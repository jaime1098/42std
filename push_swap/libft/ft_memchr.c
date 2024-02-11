/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 03:42:04 by joltra-r          #+#    #+#             */
/*   Updated: 2023/09/24 15:55:12 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memchr(const void *ptr, int c, size_t n)
{
	const unsigned char		*dst;
	unsigned char			ch;

	ch = (unsigned char)c;
	dst = (const unsigned char *)ptr;
	while (n > 0)
	{
		if (*dst == ch)
			return ((void *)dst);
		dst++;
		n--;
	}
	return (NULL);
}

/*int	main(void)
{
	int tab[7] = {-49, 49, 1, -1, 0, -2, 2};
	printf("Original: %s\n", memchr(tab, -1, 7));
	printf("My function: %s", ft_memchr(tab, -1, 7));
	return (0);
}*/