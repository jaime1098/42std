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

#include "so_long.h"

void	invalidchar(void)
{
	write(1, "Error, invalid characteres", 26);
	exit(1);
}

void	invalidmap(void)
{
	write(1, "Error, invalid map", 18);
	exit(1);
}

void	invalidfd(void)
{
	write(1, "Error, invalid fd", 17);
	exit(1);
}

void	invalidarg(void)
{
	write(1, "Error, invalid argument", 23);
	exit(1);
}
