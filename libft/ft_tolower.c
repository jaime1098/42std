/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:50:46 by joltra-r          #+#    #+#             */
/*   Updated: 2023/09/19 11:50:49 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_tolower(int c)
{
	while (c >= 65 && c <= 90)
		c = c + 32;
	return (c);
}
/*
int main()
{
int cmayusr;
int cmayusft;
cmayusr = 65;
cmayusft = 66;
int cminusr = tolower(cmayusr);
printf("mayus = %c\n", cmayusr);
printf("minus = %c\n", cminusr);
int cminusft = ft_tolower(cmayusft);
printf("mayus = %c\n", cmayusft);
printf("minus = %c\n", cminusft);
return 0;
}*/
