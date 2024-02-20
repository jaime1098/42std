/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 12:48:56 by joltra-r          #+#    #+#             */
/*   Updated: 2023/09/16 13:44:55 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isprint(int ch)
{
	while (ch >= 32 && ch <= 126)
		return (1);
	return (0);
}
/*
int main()
{
	int ch = 'a';
	int vh = 12;
	
	printf("printeable = %i\n", ft_isprint(ch));
	printf("no printeable = %i\n", ft_isprint(vh));
	return (0);
}*/
