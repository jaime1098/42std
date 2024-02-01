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

void	charge_images(t_game *game)
{
	int	width;
	int	height;
	size_t	i;
	size_t	j;
	
	width = 100;
	height = 100;
	game->pj = mlx_xpm_file_to_image(game->mlx, "../sprites/pj.xpm", &width, &height);
	game->grass = mlx_xpm_file_to_image(game->mlx, "../sprites/grass.xpm", &width, &height);
	game->wall = mlx_xpm_file_to_image(game->mlx, "../sprites/wall.xpm", &width, &height);
	game->coin = mlx_xpm_file_to_image(game->mlx, "../sprites/coin.xpm", &width, &height);
	game->exit = mlx_xpm_file_to_image(game->mlx, "../sprites/exit.xpm", &width, &height);
	i = 0;
	while (i < game->rows)
	{
		j = 0;
		while (j < game->cols)
		{
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->wall, j*32, i*32);
			if (game->map[i][j] == '0') 
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->grass, j*32, i*32);
			if (game->map[i][j] == 'P') 
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->pj, j*32, i*32);
			if (game->map[i][j] == 'C') 
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->coin, j*32, i*32);
			if (game->map[i][j] == 'E') 
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->exit, j*32, i*32);
			j++;
		}
		i++;
	}
}
/*void	inizialite_sprites(t_game *game)
{}*/