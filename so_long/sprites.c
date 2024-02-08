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

	width = 128;
	height = 128;
	game->pj[0] = mlx_xpm_file_to_image(game->mlx, CHARIZARDF, &width, &height);
	game->pj[1] = mlx_xpm_file_to_image(game->mlx, CHARIZARDB, &width, &height);
	game->pj[2] = mlx_xpm_file_to_image(game->mlx, CHARIZARDR, &width, &height);
	game->pj[3] = mlx_xpm_file_to_image(game->mlx, CHARIZARDL, &width, &height);
	game->grass = mlx_xpm_file_to_image(game->mlx, GRASS, &width, &height);
	game->wall = mlx_xpm_file_to_image(game->mlx, WATERFALL, &width, &height);
	game->coin = mlx_xpm_file_to_image(game->mlx, POKEBALL, &width, &height);
	game->exit = mlx_xpm_file_to_image(game->mlx, CPOKE, &width, &height);
}

void	draw_map(t_game *game, int x)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (++i < game->rows)
	{
		j = -1;
		while (++j < game->cols)
		{
			if (game->map_cpy[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->wall, j * 128, i * 128);
			if (game->map_cpy[i][j] == '0') 
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->grass, j * 128, i * 128);
			if (game->map_cpy[i][j] == 'P') 
			{
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->grass, j * 128, i * 128);
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->pj[x], j * 128, i * 128);
			}
			if (game->map_cpy[i][j] == 'C')
				{
					mlx_put_image_to_window(game->mlx, game->mlx_win, game->grass, j * 128, i * 128);
					mlx_put_image_to_window(game->mlx, game->mlx_win, game->coin, j * 128, i * 128);
				}
			if (game->map_cpy[i][j] == 'E')
			{
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->grass, j * 128, i * 128);
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->exit, j * 128, i * 128);
			}
		}
	}
}
/*void	exit(t_game *game)
{
	if (game->map_cpy[game.x][game.y] == 'E')
		if (game->coin == 0)
			ft_close(game)
}*/
