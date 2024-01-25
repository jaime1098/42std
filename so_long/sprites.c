/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:36:34 by joltra-r          #+#    #+#             */
/*   Updated: 2024/01/16 14:36:35 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    charge_images(t_game *game)
{
    int width;
    int height;

    width = 100;
    height = 100;
    game->sea = mlx_xpm_file_to_image(game->mlx, "/Users/joltra-r/student/sprites/sea.xpm", &width, &height);
	game->pj = mlx_xpm_file_to_image(game->mlx, "/Users/joltra-r/student/sprites/New-Piskel.xpm", &width, &height);
} 
void	inizialite_sprites(t_game *game)
{
    mlx_put_image_to_window(game->mlx, game->mlx_win, game->sea, 0, 0);
}