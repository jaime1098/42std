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
	char	*line;

	(*game).rows = 0;
	(*game).fd = open(game->ber, O_RDONLY);
	if ((*game).fd < 0)
		printf("Error opening file");
	line = get_next_line((*game).fd);
	while ((line != NULL))
	{
		(*game).rows++;
		free(line);
		line = get_next_line((*game).fd);
	}
	free(line);
	close((*game).fd);
}

void	read_map(t_game *game)
{
	int		i;
	char	*line;

	(*game).fd = open(game->ber, O_RDONLY);
	i = 0;
	line = get_next_line((*game).fd);
	if (!line)
	{
		printf("Error, no map");
		exit(1);
	}
	while (line != NULL)
	{
		(*game).map[i] = line;
		printf("%s", (*game).map[i]);
		line = get_next_line((*game).fd);
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
		exit(1);
	l = ft_strlen(argv[1]);
	if (argv[1])
		if (ft_strncmp(argv[1] + l - 4, ".ber", 4) != 0)
			exit (1);
	game.pnum = 0;
	game.cnum = 0;
	game.exnum = 0;
	game.ber = argv[1];
	check_rows(&game);
	game.map = (char **)malloc((game.rows + 1) * sizeof(char *));
	read_map(&game);
	check_map(game);
	free(game.map);
	return (0);
}
