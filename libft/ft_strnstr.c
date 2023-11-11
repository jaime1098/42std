/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 03:14:18 by joltra-r          #+#    #+#             */
/*   Updated: 2023/09/24 16:02:32 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strnstr(const char *str, const char *obj, size_t n)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (obj[0] == '\0')
		return ((char *)str);
	while (str[i] != '\0' && (unsigned int)i < (unsigned int)n)
	{
		if (str[i] == obj[j])
		{
			j++;
			if (obj[j] == '\0')
				return ((char *)str + i - j + 1);
		}
		else
		{
			i = i - j;
			j = 0;
		}
		i++;
	}
	return (0);
}

/*int	main(void)
{
	printf("Original: %s\n", strnstr("abcd\0abcd", "abcd", -1));
	printf("My function: %s", ft_strnstr("abcd\0abcd", "abcd", -1));
	return (0);
}*/