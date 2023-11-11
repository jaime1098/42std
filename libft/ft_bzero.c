/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:08:51 by joltra-r          #+#    #+#             */
/*   Updated: 2023/09/16 17:08:53 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>

void	ft_bzero(void *str, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = str;
	i = 0;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
}
/*
int main()
{
	char str[20] = "Hello World";
	char ptr[20] = "CROTOLAMO";
	size_t n = sizeof(str) - 1;

	bzero(ptr, n);
	printf("ptr = %s\n", ptr);
	ft_bzero(str, n);
	printf("str = %s\n", str);

	return (0);
}
*/