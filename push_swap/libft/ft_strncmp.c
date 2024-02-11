/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:01:48 by joltra-r          #+#    #+#             */
/*   Updated: 2023/09/19 12:01:49 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	if (n == 0)
		return (0);
	while (*str1 == *str2 && *str1 && *str2)
	{
		if (n == 1)
			return (0);
		else
		{
			str1++;
			str2++;
			n--;
		}
	}
	return ((unsigned char)(*str1) - (unsigned char)(*str2));
}

/*int	main(void)
{
	printf("Original: %i\n", strncmp("atoms\0\0\0\0", "atoms\0abc", 8));
	printf("My function: %i", ft_strncmp("atoms\0\0\0\0", "atoms\0abc", 8));
	return (0);
}*/
