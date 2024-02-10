/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:02:20 by joltra-r          #+#    #+#             */
/*   Updated: 2024/01/07 14:02:22 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_coins(t_game game)
{
	int	i;
	int	j;

	i = 1;
	game.cnum = 0;
	game.exnum = 0;
	while (i < (int)game.rows)
	{
		j = 0;
		while (j++ < (int)game.cols)
		{
			if (game.map[i][j] == 'C')
				game.cnum++;
			if (game.map[i][j] == 'E')
				game.exnum++;
		}
		i++;
	}
	if (game.exnum != 0)
		invalidmap();
	if (game.cnum != 0)
		invalidmap();
}

void	check_complete(t_game game, char u, char n)
{
	search_e(&game);
	if (game.map[game.y - 1][game.x] != u && game.map[game.y - 1][game.x] != n)
	{
		game.y -= 1;
		check_complete(game, u, n);
		game.y += 1;
	}
	if (game.map[game.y + 1][game.x] != u && game.map[game.y + 1][game.x] != n)
	{
		game.y += 1;
		check_complete(game, u, n);
		game.y -= 1;
	}
	if (game.map[game.y][game.x - 1] != u && game.map[game.y][game.x - 1] != n)
	{
		game.x -= 1;
		check_complete(game, u, n);
		game.x += 1;
	}
	if (game.map[game.y][game.x + 1] != u && game.map[game.y][game.x + 1] != n)
	{
		game.x += 1;
		check_complete(game, u, n);
		game.x -= 1;
	}
}
/*void	check_complete(t_game game)
{
	game.map[game.y][game.x] = '1';
	if (game.map[game.y - 1][game.x] != '1')
	{
		game.y -= 1;
		check_complete(game);
		game.y += 1;
	}
	if (game.map[game.y + 1][game.x] != '1')
	{
		game.y += 1;
		check_complete(game);
		game.y -= 1;
	}
	if (game.map[game.y][game.x - 1] != '1')
	{
		game.x -= 1;
		check_complete(game);
		game.x += 1;
	}
	if (game.map[game.y][game.x + 1] != '1')
	{
		game.x += 1;
		check_complete(game);
		game.x -= 1;
	}
}*/

void	check_characteres(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (++i < (int)game->rows)
	{
		j = 0;
		while (j++ < (int)game->cols)
		{
			if (!ft_strchr_sl("01PECN\n", game->map[i][j]))
				invalidchar();
			if (game->map_cpy[i][j] == 'P')
			{
				game->pnum++;
				game->y = i;
				game->x = j;
			}
			else if (game->map_cpy[i][j] == 'C')
				game->cnum++;
			else if (game->map_cpy[i][j] == 'E')
				game->exnum++;
		}
	}
}

void	check_limits(t_game game)
{
	int		i;
	size_t	length;

	i = 0;
	while (i < (int)game.cols - 1)
	{
		if (game.map[0][i] != '1' || game.map[game.rows - 1][i] != '1')
			invalidmap();
		i++;
	}
	i = 0;
	while (i < (int)game.rows)
	{
		if (game.map[i][0] != '1' || game.map[i][game.cols - 1] != '1')
			invalidmap();
		i++;
	}
	i = -1;
	while (++i < (int)game.rows - 1)
	{
		length = ft_strlen(game.map[i]);
		if (length - 1 != game.cols)
			invalidmap();
	}
}

void	check_map(t_game *game)
{
	char	u;
	char	n;

	u = '1';
	n = 'N';
	game->pnum = 0;
	game->cnum = 0;
	game->exnum = 0;
	check_limits(*game);
	check_characteres(game);
	if (game->pnum != 1 || game->exnum != 1)
		invalidchar();
	else if (game->cnum < 1)
		invalidchar();
	check_complete(*game, u, n);
	check_coins(*game);
}
