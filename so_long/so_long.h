/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 12:59:36 by joltra-r          #+#    #+#             */
/*   Updated: 2023/12/30 12:59:37 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "mlx.h"

typedef struct s_game
{
	char	**map;
	char	**map_cpy;
	void	*mlx;
	void	*mlx_win;
	void	*pj[4];
	void	*grass;
	void	*wall;
	void	*coin;
	void	*exit;
	char	*line;
	char	*ber;
	size_t	rows;
	size_t	cols;
	int		fd;
	int		pnum;
	int		cnum;
	int		exnum;
	int		x;
	int		y;
	int		auxx;
	int		auxy;
}	t_game;

int		main(int argc, char **argv);
void	invalidmap(void);
void	invalidfd(void);
void	invalidarg(void);
void	invalidchar(void);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
char	*ft_strdup(const char *s);
int		ft_strlen(const char *str);
void	read_map(t_game *game);
void	check_map(t_game *game);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *str, int c);
char	*get_next_line(int fd);
void	charge_images(t_game *game);
void	draw_map(t_game *game, int x);
int		keyboard(int keycode, t_game *game);
void	see_x_y(t_game *game);
int		ft_close(t_game *game);

# define CHARIZARDF "/Users/joltra-r/student/so_long/sprites/Charizard-front.xpm"
# define CHARIZARDB "/Users/joltra-r/student/so_long/sprites/Charizard-back.xpm"
# define CHARIZARDR "/Users/joltra-r/student/so_long/sprites/Charizard-right.xpm"
# define CHARIZARDL "/Users/joltra-r/student/so_long/sprites/Charizard-left.xpm"
# define WATERFALL "/Users/joltra-r/student/so_long/sprites/Waterfall-1.xpm"
# define GRASS "/Users/joltra-r/student/so_long/sprites/Grass.xpm"
# define POKEBALL "/Users/joltra-r/student/so_long/sprites/Poké_Ball_EP.xpm"
# define CPOKE "/Users/joltra-r/student/so_long/sprites/CentroPokemon.xpm"

#endif
