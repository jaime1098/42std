/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 16:00:10 by joltra-r          #+#    #+#             */
/*   Updated: 2023/12/30 16:00:11 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
/*void	search_e(t_game *game)
{
	game->map[game->y][game->x] = '1';
	game->auxy = game->y;
	game->auxx = game->x;
	if (game->map[game->y - 1][game->x] == 'E')
		game->auxy -= 1;
	if (game->map[game->y + 1][game->x] == 'E')
		game->auxy += 1;
	if (game->map[game->y][game->x - 1] == 'E')
		game->auxx -= 1;
	if (game->map[game->y][game->x + 1] == 'E')
		game->auxx += 1;
	game->map[game->auxy][game->auxx] = '1';
}

void	check_complete(t_game game)
{
	search_e(&game);
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
void	search_e(t_game *game)
{
	game->map[game->y][game->x] = '1';
	game->auxy = game->y;
	game->auxx = game->x;
	if (game->map[game->y - 1][game->x] == 'E')
		game->auxy -= 1;
	if (game->map[game->y + 1][game->x] == 'E')
		game->auxy += 1;
	if (game->map[game->y][game->x - 1] == 'E')
		game->auxx -= 1;
	if (game->map[game->y][game->x + 1] == 'E')
		game->auxx += 1;
	game->map[game->auxy][game->auxx] = '1';
}

void	see_x_y(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (++i < (int)game->rows)
	{
		j = 0;
		while (j++ < (int)game->cols)
		{
			if (game->map_cpy[i][j] == 'P')
			{
				game->y = j;
				game->x = i;
			}
		}
	}
}

int	ft_close(t_game *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	exit(0);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dup;
	size_t	length;

	length = ft_strlen(s) + 1;
	i = 0;
	dup = malloc(length);
	if (!dup)
		return (NULL);
	while (i < (int)length)
	{
		dup[i] = s[i];
		i++;
	}
	return (dup);
}

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	if (n == 0)
		return (0);
	while (*str1 == *str2 && *str1 && *str2)
	{
		if (n == 1)
			return (0);
		else
		{
			str1++;
			str2++;
			n--;
		}
	}
	return ((unsigned char)(*str1) - (unsigned char)(*str2));
}
