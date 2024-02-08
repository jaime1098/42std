/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:44:24 by joltra-r          #+#    #+#             */
/*   Updated: 2024/02/03 16:44:26 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_a(t_game *game)
{
	int x;

	x = 3;
	if (!((game->map_cpy[game->x][game->y - 1]) == '1'))
	{
		if (game->map_cpy[game->x][game->y - 1] == 'E')
			if (game->cnum == 0)
				ft_close(game);
		if (!((game->map_cpy[game->x][game->y - 1]) == 'E'))
		{
			if (game->map_cpy[game->x][game->y - 1] == 'C')
				game->cnum--;
			game->map_cpy[game->x][game->y] = '0';
			game->map_cpy[game->x][game->y - 1] = 'P';
			game->y--;
			draw_map(game, x);
		}
	}
	return (1);
}

int	ft_s(t_game *game)
{
	int x;

	x = 0;
	if (!((game->map_cpy[game->x + 1][game->y]) == '1'))
	{
		if (!((game->map_cpy[game->x + 1][game->y]) == 'E'))
		{
		if (game->map_cpy[game->x + 1][game->y] == 'E')
			if (game->cnum == 0)
				ft_close(game);
			if (game->map_cpy[game->x + 1][game->y] == 'C')
				game->cnum--;
			game->map_cpy[game->x][game->y] = '0';
			game->map_cpy[game->x + 1][game->y] = 'P';
			game->x++;
			draw_map(game, x);
		}
	}
	return (1);
}

int	ft_d(t_game *game)
{
	int x;

	x = 2;
	if (!((game->map_cpy[game->x][game->y + 1]) == '1'))
	{
		if (game->map_cpy[game->x][game->y + 1] == 'E')
			if (game->cnum == 0)
				ft_close(game);
		if (!((game->map_cpy[game->x][game->y + 1]) == 'E'))
		{
			if (game->map_cpy[game->x][game->y + 1] == 'C')
				game->cnum--;
			game->map_cpy[game->x][game->y] = '0';
			game->map_cpy[game->x][game->y + 1] = 'P';
			game->y++;
			draw_map(game, x);
		}
	}
	return (1);
}

int	ft_w(t_game *game)
{
	int x;

	x = 1;
	if (!((game->map_cpy[game->x - 1][game->y]) == '1'))
	{
		if (game->map_cpy[game->x - 1][game->y] == 'E')
			if (game->cnum == 0)
				ft_close(game);
		if (!((game->map_cpy[game->x - 1][game->y]) == 'E'))
		{
			if (game->map_cpy[game->x - 1][game->y] == 'C')
				game->cnum--;
			game->map_cpy[game->x][game->y] = '0';
			game->map_cpy[game->x - 1][game->y] = 'P';
			game->x--;
			draw_map(game, x);
		}
	}
	return (1);
}

int	keyboard(int keycode, t_game *game)
{
	int count;

	count = 0;
	if (keycode == 53)
		ft_close(game);
	if (keycode == 0 || keycode == 123)
		count += ft_a(game);
	if (keycode == 1 || keycode == 125)
		count += ft_s(game);
	if (keycode == 2 || keycode == 124)
		count += ft_d(game);
	if (keycode == 13 || keycode == 126)
		count += ft_w(game);
	return (count);
}
