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

typedef struct s_sprites
{
		void	*mario;
}				t_sprites;

typedef struct s_game
{
	char	**map;
	char	**map_cpy;
	void	*mlx;
	void	*mlx_win;
	void	*pj;
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
	t_sprites	*spr;
}	t_game;

int		main(int argc, char **argv);
void	invalidmap(void);
void	invalidfd(void);
void	invalidarg(void);
void	invalidchar(void);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
void	read_map(t_game *game);
void	check_map(t_game game);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *str, int c);
char	*get_next_line(int fd);
void    charge_images(t_game *game);
void	inizialite_sprites(t_game *game);

# define MARIO "/Users/joltra-r/student/sprites/New-Piskel.xpm"

#endif
