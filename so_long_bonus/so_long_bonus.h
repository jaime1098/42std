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

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include "printf/ft_printf.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "mlx.h"

typedef struct s_game
{
	char	**map;
	char	**map_cpy;
	void	*mlx;
	void	*mlx_win;
	void	*pj[4];
	void	*tree[7];
	void	*grass;
	void	*coin;
	void	*enemy;
	void	*exit;
	char	*line;
	char	*ber;
	char	*moves;
	int		ch;
	int		count;
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
void	checkarg(int argc, char **argv);
char	*ft_strjoin_sl(char *s1, char *s2);
void	invalidmap(void);
void	invalidfd(void);
void	invalidarg(void);
void	invalidchar(void);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
char	*ft_strdup(const char *s);
int		ft_strlen(const char *str);
void	read_map(t_game *game);
void	check_map(t_game *game);
void	search_e(t_game *game);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr_sl(char *str, int c);
char	*get_next_line(int fd);
char	*ft_itoa(int n);
void	charge_images(t_game *game);
int		draw_map(t_game *game);
int		keyboard(int keycode, t_game *game);
void	see_x_y(t_game *game);
int		ft_close(t_game *game);

# define TREENOAPPLE "sprites/NoAppleTree.xpm"
# define TREEAPPLE "sprites/AppleTree.xpm"
# define TREEMIDDLE "sprites/MiddleAppleTree.xpm"
# define CHARIZARDF "sprites/Charizard-front.xpm"
# define CHARIZARDB "sprites/Charizard-back.xpm"
# define CHARIZARDR "sprites/Charizard-right.xpm"
# define CHARIZARDL "sprites/Charizard-left.xpm"
# define DOGC "sprites/dogcoming.xpm"
# define DOGE "sprites/dogeating.xpm"
# define DOGG "sprites/doggoing.xpm"
# define WATERFALL "sprites/Waterfall-1.xpm"
# define GRASS "sprites/Grass.xpm"
# define POKEBALL "sprites/Poké_Ball_EP.xpm"
# define TR "sprites/TeamRocket.xpm"
# define CPOKE "sprites/CentroPokemon.xpm"

#endif
