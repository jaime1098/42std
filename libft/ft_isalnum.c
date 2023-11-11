/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:00:27 by joltra-r          #+#    #+#             */
/*   Updated: 2023/09/16 13:38:07 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isalnum(int ch)
{
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		return (1);
	if (ch >= '0' && ch <= '9')
		return (1);
	return (0);
}
/*
int main(void)
{
	int	n1;
	int	n2;
	
	n1 = '#';
	n2 = '2';
    printf("%i\n", ft_isalnum(n1));
    printf("%i\n", ft_isalnum(n2));
}*/
