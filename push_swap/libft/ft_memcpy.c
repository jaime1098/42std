/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:20:55 by joltra-r          #+#    #+#             */
/*   Updated: 2023/10/22 18:52:28 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int					i;
	int					cont;
	unsigned char		*dst;
	const unsigned char	*sorc;

	dst = dest;
	sorc = src;
	i = 0;
	cont = 0;
	if (!dest && !sorc)
		return (0);
	while ((size_t)cont < n)
	{
		dst[i] = sorc[i];
		i++;
		cont++;
	}
	return (dst);
}
/*
int main()
{
  char dest[6] = "";
  char dest2[6] = "";
  const char src[5] = "";
  size_t n = sizeof(src) -1;
  
  memcpy(dest2, src, n);
  printf("memcpy org = %s\n", dest2);
  ft_memcpy(dest, src, n);
  printf("memcpy = %s\n", dest);
  return (0);
}*/
