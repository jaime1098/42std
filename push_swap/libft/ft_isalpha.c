/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:51:16 by joltra-r          #+#    #+#             */
/*   Updated: 2023/09/16 14:53:34 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isalpha(int ch)
{
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		return (1);
	return (0);
}
/*
int main(void)
{
	int	ch1;
	int	ch2;

	ch1 = 'A';
	ch2 = '1';
	printf("%i\n", ft_isalpha(ch1));
    printf("%i\n", ft_isalpha(ch2));
}*/
