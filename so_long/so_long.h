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

typedef struct s_game
{
	char	**map;
	char	*ber;
	size_t	rows;
	size_t	cols;
	int		fd;
	int		pnum;
	int		cnum;
	int		exnum;
	int		x;
	int		y;
}	t_game;

int		main(int argc, char **argv);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
void	check_map(t_game game);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *str, int c);
char	*get_next_line(int fd);

#endif
