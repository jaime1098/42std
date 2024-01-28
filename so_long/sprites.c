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
	
	width = 42;
	height = 42;
	read_map(&game);
	game->pj = mlx_xpm_file_to_image(game->mlx, "/Users/joltra-r/student/sprites/pj.xpm", &width, &height);
	game->grass = mlx_xpm_file_to_image(game->mlx, "/Users/joltra-r/student/sprites/grass.xpm", &width, &height);
	game->wall = mlx_xpm_file_to_image(game->mlx, "/Users/joltra-r/student/sprites/wall.xpm", &width, &height);
	i = 0;
	while (i < game->rows)
	{
		j = 0;
		while (j < game->cols)
		{
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->wall, i*32, j*32);
			if (game->map[i][j] == '0') 
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->grass, i*32, j*32);
			if (game->map[i][j] == 'P') 
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->pj, i*32, j*32);
			j++;
		}
		i++;
	}
}
/*void	inizialite_sprites(t_game *game)
{}*/