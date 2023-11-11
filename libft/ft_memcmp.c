/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 03:48:12 by joltra-r          #+#    #+#             */
/*   Updated: 2023/09/24 15:56:27 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	const unsigned char	*stru1;
	const unsigned char	*stru2;

	stru1 = (const unsigned char *)str1;
	stru2 = (const unsigned char *)str2;
	while (n > 0)
	{
		if (*stru1 != *stru2)
			return ((*stru1) - (*stru2));
		stru1++;
		stru2++;
		n--;
	}
	return (0);
}
/*int	main(void)
{
	printf("Original: %i\n", memcmp("abcdefgh", "abcdwxyz", 6));
	printf("My function: %i", ft_memcmp("abcdefgh", "abcdwxyz", 6));
	return (0);
}*/