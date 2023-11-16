/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:12:08 by joltra-r          #+#    #+#             */
/*   Updated: 2023/11/16 13:12:09 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "libftprintf.h"

int	main(void)
{
	int	testft;
	int	testorg;

	testft = ft_printf("Testft: %c\n", 'a');
	printf("lenft: %d\n", testft);
	testorg = printf("Testorg: %c\n", 'a');
	printf("lenorg: %d\n", testorg);
	return (0);
}
