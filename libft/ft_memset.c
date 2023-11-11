/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 12:52:31 by joltra-r          #+#    #+#             */
/*   Updated: 2023/09/16 13:26:06 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>

void	*ft_memset(void *str, int ch, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = str;
	i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char) ch;
		i++;
	}
	return (str);
}
/*
int main()
{
	char str[20] = "Hello World";
	char ptr[20] = "Hello World";
	int i;
	int ch = 'A';
	size_t n = sizeof(str) - 1;

	i = 0;
	memset(str, ch + 1, n);
	printf("str = %s\n", str);
	ft_memset(str, ch, n);
	printf("str = %s\n", str);

	return (0);
}*/
