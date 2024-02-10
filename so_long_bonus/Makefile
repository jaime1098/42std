NAME = so_long_bonus

SRCS =	so_long.c so_long_utils.c so_long_map.c get_next_line.c \
		get_next_line_utils.c errors.c sprites.c keyboard.c ft_itoa.c

OBJECTS = $(SRCS:.c=.o)

CFLAGS := -Wall -Wextra -Werror -Imlx 
REMOVE = rm -f
CC := cc

all: $(NAME)

$(NAME): $(OBJECTS) printf/libftprintf.a mlx/libmlx.a
	$(CC) $(OBJECTS) printf/libftprintf.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

mlx/libmlx.a:
	make -C mlx/

printf/libftprintf.a:
	make -C printf/

run:
	./so_long map1.ber

clean:
	$(REMOVE) $(OBJECTS)
	$(REMOVE) $(OBJECTS_BONUS)
	make -C mlx/ clean
	make -C printf/ fclean

fclean: clean
	$(REMOVE) $(NAME)
	$(REMOVE) $(NAME_BONUS)

re: fclean all