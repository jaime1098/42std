/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 12:59:17 by joltra-r          #+#    #+#             */
/*   Updated: 2023/12/30 12:59:19 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_rows(t_game *game)
{
	(*game).rows = 0;
	(*game).fd = open(game->ber, O_RDONLY);
	if ((*game).fd < 0)
		invalidfd();
	game->line = get_next_line((*game).fd);
	while ((game->line != NULL))
	{
		(*game).rows++;
		free(game->line);
		game->line = get_next_line((*game).fd);
	}
	free(game->line);
	close((*game).fd);
}

void	read_map(t_game *game)
{
	int		i;

	(*game).fd = open(game->ber, O_RDONLY);
	i = 0;
	game->line = get_next_line((*game).fd);
	if (!game->line)
		invalidmap();
	while (game->line != NULL)
	{
		(*game).map[i] = game->line;
		game->line = get_next_line((*game).fd);
		i++;
	}
	(*game).map[i] = NULL;
	(*game).cols = ft_strlen((*game).map[game->rows - 1]);
	close((*game).fd);
}

int	main(int argc, char **argv)
{
	t_game	game;
	int		l;

	if (argc != 2 || argv[1] == '\0')
		invalidarg();
	l = ft_strlen(argv[1]);
	if (argv[1])
		if (ft_strncmp(argv[1] + l - 4, ".ber", 4) != 0)
			invalidarg();
	game.mlx = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx, 1920, 1080, "so_long");
	game.pnum = 0;
	game.cnum = 0;
	game.exnum = 0;
	game.ber = argv[1];
	check_rows(&game);
	game.map = (char **)malloc((game.rows + 1) * sizeof(char *));
	read_map(&game);
	check_map(game);
	//free(game.map);
	charge_images(&game);
	inizialite_sprites(&game);
	mlx_loop(game.mlx);
	return (0);
}
