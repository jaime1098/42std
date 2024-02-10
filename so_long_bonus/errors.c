/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 16:23:47 by joltra-r          #+#    #+#             */
/*   Updated: 2024/01/07 16:23:48 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	invalidchar(void)
{
	write(1, "Error, invalid characteres\n", 27);
	exit(1);
}

void	invalidmap(void)
{
	write(1, "Error, invalid map\n", 19);
	exit(1);
}

void	invalidfd(void)
{
	write(1, "Error, invalid fd\n", 18);
	exit(1);
}

void	invalidarg(void)
{
	write(1, "Error, invalid argument\n", 24);
	exit(1);
}

void	checkarg(int argc, char **argv)
{
	size_t	l;

	if (argc != 2 || argv[1] == '\0')
		invalidarg();
	l = ft_strlen(argv[1]);
	if (argv[1])
		if (ft_strncmp(argv[1] + l - 4, ".ber", 4) != 0)
			invalidarg();
}
