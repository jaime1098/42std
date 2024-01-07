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

#include "so_long.h"

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
		printf("\nError\n");
	if (game.cnum != 0)
		printf("\nError\n");
}

void	check_complete(t_game game)
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
}

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
			if (!ft_strchr("01PEC\n", game->map[i][j]))
				printf("\nError, invalid char\n");
			if (game->map[i][j] == 'P')
			{
				game->pnum++;
				game->y = i;
				game->x = j;
			}
			else if (game->map[i][j] == 'C')
				game->cnum++;
			else if (game->map[i][j] == 'E')
				game->exnum++;
		}
	}
	printf("\nP = %d\nC = %d\nE = %d\n", game->pnum, game->cnum, game->exnum);
	if (game->pnum != 1 || game->exnum != 1)
		printf("\nError, characters error\n");
	else if (game->cnum < 1)
		printf("\nError, characters error\n");
}

void	check_limits(t_game game)
{
	int		i;
	size_t	length;

	i = 0;
	while (i < (int)game.cols - 1)
	{
		if (game.map[0][i] != '1' || game.map[game.rows - 1][i] != '1')
			printf("\nError, invalid map\n");
		i++;
	}
	i = 0;
	while (i < (int)game.rows)
	{
		if (game.map[i][0] != '1' || game.map[i][game.cols - 1] != '1')
			printf("\nError, invalid map\n");
		i++;
	}
	i = -1;
	while (++i < (int)game.rows - 1)
	{
		length = ft_strlen(game.map[i]);
		if (length - 1 != game.cols)
			printf("\nError, invalid map");
	}
}

void	check_map(t_game game)
{
	int	i;

	i = -1;
	check_limits(game);
	check_characteres(&game);
	check_complete(game);
	while (++i < (int)game.rows)
		printf("%s", game.map[i]);
	check_coins(game);
}
