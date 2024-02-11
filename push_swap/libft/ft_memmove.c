/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:48:36 by joltra-r          #+#    #+#             */
/*   Updated: 2023/10/22 18:55:46 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

#include <stdio.h>
#include <string.h>

char	*dst_menor(char *dst, const char *sorc, size_t n)
{
	int	i;

	i = 0;
	while (i < (int)n)
	{
		dst[i] = sorc[i];
		i++;
	}
	return (dst);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int			i;
	char		*dst;
	const char	*sorc;

	dst = (char *)dest;
	sorc = (char *)src;
	if (!dest && !sorc)
		return (0);
	if (dst <= sorc)
		dst = dst_menor(dst, sorc, n);
	else
	{
		i = (int)n - 1;
		while (i >= 0)
		{
			dst[i] = sorc[i];
			i--;
		}
	}
	return (dst);
}

/*int main()
{
  char dest[10];
  char dest2[10];
  const char src[] = "lorem ipsum dolor sit amet";
  size_t n = sizeof(src);
  
  memmove(dest2, src, 8);
  printf("memmove org = %s\n", dest2);
  ft_memmove(dest, src, 8);
  printf("ft_memmove = %s\n", dest);
  return (0);
}*/
