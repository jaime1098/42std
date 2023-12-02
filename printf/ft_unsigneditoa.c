/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 05:01:27 by joltra-r          #+#    #+#             */
/*   Updated: 2023/09/24 15:54:18 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*mymalloc(unsigned int n, size_t length)
{
	char	*num;
	int		i;

	num = malloc(length + 1);
	if (!num)
		return (NULL);
	i = 0;
	i = (int)length - 1;
	while (n / 10)
	{
		num[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
	num[i] = n % 10 + '0';
	num[(int)length] = '\0';
	return (num);
}

char	*ft_unsigneditoa(unsigned int n)
{
	size_t			length;
	unsigned int	aux;
	char			*num;

	aux = n;
	length = 1;
	while (aux / 10)
	{
		aux /= 10;
		length++;
	}
	num = mymalloc(n, length);
	return (num);
}

/*int main()
{	
	char *result = ft_itoa(-2147483648);
	printf ("Resultado: %s\n", result);
	free (result);
	return 0;
}*/
