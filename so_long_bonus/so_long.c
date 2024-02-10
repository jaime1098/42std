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

#include "so_long_bonus.h"

char	*ft_strjoin_sl(char *s1, char *s2)
{
	char	*strcomplete;
	size_t	length;
	int		i;
	int		j;

	i = -1;
	j = 0;
	length = ft_strlen(s1) + ft_strlen(s2) + 1;
	strcomplete = malloc(length);
	if (strcomplete == NULL)
		return (NULL);
	while (s1[++i] != '\0')
		strcomplete[i] = s1[i];
	while (s2[j] != '\0')
		strcomplete[i++] = s2[j++];
	strcomplete[i] = '\0';
	return (strcomplete);
}

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
		(*game).map_cpy[i] = ft_strdup((*game).line);
		(*game).map[i] = game->line;
		game->line = get_next_line((*game).fd);
		i++;
	}
	(*game).map[i] = NULL;
	(*game).map_cpy[i] = NULL;
	(*game).cols = ft_strlen((*game).map[game->rows - 1]);
	close((*game).fd);
}

int	main(int argc, char **argv)
{
	t_game	game;

	game.ch = 0;
	game.count = 0;
	checkarg(argc, argv);
	game.ber = argv[1];
	check_rows(&game);
	game.map = (char **)malloc((game.rows + 1) * sizeof(char *));
	game.map_cpy = (char **)malloc((game.rows + 1) * sizeof(char *));
	read_map(&game);
	game.mlx = mlx_init();
	game.mlx_win = mlx_new_window \
	(game.mlx, game.cols * 128, game.rows * 128, "so_long_bonus");
	check_map(&game);
	charge_images(&game);
	see_x_y(&game);
	mlx_hook(game.mlx_win, 2, 0, keyboard, &game);
	mlx_hook(game.mlx_win, 17, 0, ft_close, &game);
	mlx_loop_hook(game.mlx, draw_map, &game);
	mlx_loop(game.mlx);
	return (0);
}
