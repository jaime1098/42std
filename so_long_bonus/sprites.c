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

#include "so_long_bonus.h"

void	dog_spawn(int *anim, int *interval, int *aux)
{
	if ((*aux)++ == 7000)
	{
		(*anim)++;
		*aux = 0;
		if (!(*interval))
		{
			*anim = 6000;
			*interval = 1;
		}
		else
			*interval = 0;
	}
}

void	timer(int *anim)
{
	static int	aux;
	static int	interval;

	(*anim)++;
	if (*anim == 2999)
	{
		(*anim)--;
		dog_spawn(anim, &interval, &aux);
	}
	if (*anim == 6999)
	{
		(*anim)--;
		if (aux++ == 10000)
		{
			aux = 0;
			*anim = 0;
		}
	}
}

void	pitw(t_game *game, size_t i, size_t j)
{
	static int	anim;

	i = i * 128;
	j = j * 128;
	timer(&anim);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->grass, j, i);
	if (game->map_cpy[i / 128][j / 128] == '1')
		mlx_put_image_to_window \
		(game->mlx, game->mlx_win, game->tree[anim / 1000], j, i);
	if (game->map_cpy[i / 128][j / 128] == 'P')
		mlx_put_image_to_window \
		(game->mlx, game->mlx_win, game->pj[game->ch], j, i);
	if (game->map_cpy[i / 128][j / 128] == 'C')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->coin, j, i);
	if (game->map_cpy[i / 128][j / 128] == 'E')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->exit, j, i);
	if (game->map_cpy[i / 128][j / 128] == 'N')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->enemy, j, i);
}

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
	game->tree[0] = mlx_xpm_file_to_image \
	(game->mlx, TREENOAPPLE, &width, &height);
	game->tree[1] = mlx_xpm_file_to_image \
	(game->mlx, TREEMIDDLE, &width, &height);
	game->tree[2] = mlx_xpm_file_to_image \
	(game->mlx, TREEAPPLE, &width, &height);
	game->tree[3] = mlx_xpm_file_to_image(game->mlx, DOGC, &width, &height);
	game->tree[4] = mlx_xpm_file_to_image(game->mlx, DOGE, &width, &height);
	game->tree[5] = mlx_xpm_file_to_image(game->mlx, DOGG, &width, &height);
	game->tree[6] = mlx_xpm_file_to_image \
	(game->mlx, TREENOAPPLE, &width, &height);
	game->enemy = mlx_xpm_file_to_image(game->mlx, TR, &width, &height);
	game->grass = mlx_xpm_file_to_image(game->mlx, GRASS, &width, &height);
	game->coin = mlx_xpm_file_to_image(game->mlx, POKEBALL, &width, &height);
	game->exit = mlx_xpm_file_to_image(game->mlx, CPOKE, &width, &height);
}

int	draw_map(t_game *game)
{
	size_t	i;
	size_t	j;

	i = -1;
	mlx_clear_window(game->mlx, game->mlx_win);
	game->moves = ft_itoa(game->count);
	while (++i < game->rows)
	{
		j = -1;
		while (++j < game->cols)
			pitw(game, i, j);
	}
	if (game->count == INT_MAX || game->count < 0)
	{
		mlx_string_put(game->mlx, game->mlx_win, 90, 95, 0xFFFFFFFF, "MAX");
		game->count = INT_MAX;
	}
	else
	{
		game->moves = ft_strjoin_sl("Movements:", game->moves);
		mlx_string_put(game->mlx, game->mlx_win, \
		90, 95, 0xFFFFFFFF, game->moves);
		free (game->moves);
	}
	return (1);
}
