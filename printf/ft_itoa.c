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

char	*ft_printnegative(char *num, int n, size_t length)
{
	int	i;

	i = 0;
	num[i] = '-';
	if (n == -2147483648)
	{
		n = n + 1;
		ft_printnegative(num, n, length);
		num[length] = '8';
		return (num);
	}
	n *= -1;
	i = (int)length;
	while (n / 10)
	{
		num[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
	num[i] = n % 10 + '0';
	num[(int)length + 1] = '\0';
	return (num);
}

char	*ft_printpositive(char *num, int n, size_t length)
{
	int	i;

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

char	*createmalloc(int n, size_t length)
{
	char	*num;

	if (n < 0)
	{
		num = malloc(length + 2);
		if (!num)
			return (NULL);
		ft_printnegative(num, n, length);
	}
	else
	{
		num = malloc(length + 1);
		if (!num)
			return (NULL);
		ft_printpositive(num, n, length);
	}
	return (num);
}

char	*ft_itoa(int n)
{
	size_t	length;
	int		aux;
	char	*num;

	aux = n;
	length = 1;
	while (aux / 10)
	{
		aux /= 10;
		length++;
	}
	num = createmalloc (n, length);
	return (num);
}

/*int main()
{	
	char *result = ft_itoa(-2147483648);
	printf ("Resultado: %s\n", result);
	free (result);
	return 0;
}*/
