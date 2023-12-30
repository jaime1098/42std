/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 16:00:10 by joltra-r          #+#    #+#             */
/*   Updated: 2023/12/30 16:00:11 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	if (n == 0)
		return (0);
	while (*str1 == *str2 && *str1 && *str2)
	{
		if (n == 1)
			return (0);
		else
		{
			str1++;
			str2++;
			n--;
		}
	}
	return ((unsigned char)(*str1) - (unsigned char)(*str2));
}
