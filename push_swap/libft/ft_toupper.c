/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:43:08 by joltra-r          #+#    #+#             */
/*   Updated: 2023/09/19 11:43:12 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_toupper(int c)
{
	while (c >= 97 && c <= 122)
		c = c - 32;
	return (c);
}
/*
int main()
{
int cminusr;
int cminusft;
cminusr = 97;
cminusft = 98;
int cmayusr = toupper(cminusr);
printf("minus = %c\n", cminusr);
printf("minus = %c\n", cmayusr);
int cmayusft = ft_toupper(cminusft);
printf("minus = %c\n", cminusft);
printf("minus = %c\n", cmayusft);
return 0;
}*/
