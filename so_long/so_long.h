#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../get_next_line/get_next_line.h"

typedef struct s_game
{
	char	**map;
	size_t	rows;
	size_t	cols;
	int		fd;
}               t_game;

int	    main();

#endif