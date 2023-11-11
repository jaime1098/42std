/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 04:37:24 by joltra-r          #+#    #+#             */
/*   Updated: 2023/09/24 15:51:35 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void			*mem;
	size_t			total;
	unsigned char	*null;
	int				i;

	i = 0;
	total = count * size;
	mem = malloc(total);
	if (!mem)
		return (NULL);
	null = (unsigned char *)mem;
	while (i < (int)total)
	{
		null[i] = '\0';
		i++;
	}
	return (mem);
}
