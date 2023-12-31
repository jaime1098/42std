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

/*void	complete_map(t_game *s_game)
{

}*/
void	check_exit(t_game *game)
{
	if (game->map[game->pos_y][game->pos_x] == 'E')
	{
		if(game->cnum != 0)
			return ;
		else
			game->map[game->pos_y][game->pos_x] = '1';

	}
	if (game->map[game->pos_y][game->pos_x] == 'C')
	{
		printf("\nC = %d\n", game->cnum);
		game->cnum--;
		printf("\nC = %d\n", game->cnum);
	}
	game->map[game->pos_y][game->pos_x] = '1';
}

void	check_complete(t_game game)
{
	check_exit(&game);
	if (game.map[game.pos_y - 1][game.pos_x] != '1')
	{
		game.pos_y -= 1;
		check_complete(game);
		game.pos_y += 1;
	}
	if (game.map[game.pos_y + 1][game.pos_x] != '1')
	{
		game.pos_y += 1;
		check_complete(game);
		game.pos_y -= 1;
	}
	if (game.map[game.pos_y][game.pos_x - 1] != '1')
	{
		game.pos_x -= 1;
		check_complete(game);
		game.pos_x += 1;
	}
	if (game.map[game.pos_y][game.pos_x + 1] != '1')
	{
		game.pos_x += 1;
		check_complete(game);
		game.pos_x -= 1;
	}
}
void	check_characteres(t_game *game)
{
	int	i;
	int	j;

	i = 1;
	while (i < (int)game->rows)
	{
		j = 0;
		while (j++ < (int)game->cols)
		{
			if (game->map[i][j] == 'P')
			{
				game->pnum++;
				game->pos_y = i;
				game->pos_x = j;
			}
			else if (game->map[i][j] == 'C')
				game->cnum++;
			else if (game->map[i][j] == 'E')
				game->exnum++;
		}
		i++;
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
		if (length - 1 != game. cols)
			printf("\nError, invalid map");
	}
}

void	check_map(t_game game)
{
	check_limits(game);
	check_characteres(&game);
	check_complete(game);
	int i;
	i = -1;
	while (++i <= 4)
		printf("%s", game.map[i]);
}

void	check_rows(t_game *game)
{
	char	*line;

	(*game).rows = 0;
	(*game).fd = open(game->ber, O_RDONLY);
	if ((*game).fd < 0)
		printf("Error opening file");
	while ((line = get_next_line((*game).fd)))
	{
		(*game).rows++;
		free(line);
	}
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

	if (argc != 2 || argv[1] == '\0')
	{
		printf("Error, invalid argument");
		exit(1);
	}
	if (argv[1])
		if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4) != 0)
		{
			printf("Error, invalid argument");
			exit (1);
		}
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
