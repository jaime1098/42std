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

#include "so_long_bonus.h"

int	ft_a(t_game *game)
{
	game->ch = 3;
	if (!((game->map_cpy[game->x][game->y - 1]) == '1'))
	{
		if (game->map_cpy[game->x][game->y - 1] == 'N')
		{
			game->count++;
			ft_close(game);
		}
		if (game->map_cpy[game->x][game->y - 1] == 'E')
		{
			if (game->cnum == 0)
			{
				game->count++;
				ft_close(game);
			}
		}
		if (game->map_cpy[game->x][game->y - 1] == 'C')
			game->cnum--;
		game->map_cpy[game->x][game->y] = '0';
		game->map_cpy[game->x][game->y - 1] = 'P';
		game->y--;
		return (1);
	}
	return (0);
}

int	ft_s(t_game *game)
{
	game->ch = 0;
	if (!((game->map_cpy[game->x + 1][game->y]) == '1'))
	{
		if (game->map_cpy[game->x + 1][game->y] == 'N')
		{
			game->count++;
			ft_close(game);
		}
		if (game->map_cpy[game->x + 1][game->y] == 'E')
		{
			if (game->cnum == 0)
			{
				game->count++;
				ft_close(game);
			}
		}
		if (game->map_cpy[game->x + 1][game->y] == 'C')
			game->cnum--;
		game->map_cpy[game->x][game->y] = '0';
		game->map_cpy[game->x + 1][game->y] = 'P';
		game->x++;
		return (1);
	}
	return (0);
}

int	ft_d(t_game *game)
{
	game->ch = 2;
	if (!((game->map_cpy[game->x][game->y + 1]) == '1'))
	{
		if (game->map_cpy[game->x][game->y + 1] == 'N')
		{
			game->count++;
			ft_close(game);
		}
		if (game->map_cpy[game->x][game->y + 1] == 'E')
		{
			if (game->cnum == 0)
			{
				game->count++;
				ft_close(game);
			}
		}
		if (game->map_cpy[game->x][game->y + 1] == 'C')
			game->cnum--;
		game->map_cpy[game->x][game->y] = '0';
		game->map_cpy[game->x][game->y + 1] = 'P';
		game->y++;
		return (1);
	}
	return (0);
}

int	ft_w(t_game *game)
{
	game->ch = 1;
	if (!((game->map_cpy[game->x - 1][game->y]) == '1'))
	{
		if (game->map_cpy[game->x - 1][game->y] == 'N')
		{
			game->count++;
			ft_close(game);
		}
		if (game->map_cpy[game->x - 1][game->y] == 'E')
		{
			if (game->cnum == 0)
			{
				game->count++;
				ft_close(game);
			}
		}
		if (game->map_cpy[game->x - 1][game->y] == 'C')
			game->cnum--;
		game->map_cpy[game->x][game->y] = '0';
		game->map_cpy[game->x - 1][game->y] = 'P';
		game->x--;
		return (1);
	}
	return (0);
}

int	keyboard(int keycode, t_game *game)
{
	if (keycode == 53)
		ft_close(game);
	if (keycode == 0 || keycode == 123)
		game->count += ft_a(game);
	if (keycode == 1 || keycode == 125)
		game->count += ft_s(game);
	if (keycode == 2 || keycode == 124)
		game->count += ft_d(game);
	if (keycode == 13 || keycode == 126)
		game->count += ft_w(game);
	return (0);
}
