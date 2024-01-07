NAME = solong.a

SRCS =	so_long.c so_long_utils.c so_long_map.c get_next_line.c \
		get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
REMOVE = rm -f

all: $(NAME)


$(NAME): $(OBJS)
		 ar rcs $(NAME) $(OBJS)

.c.o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
		$(REMOVE) $(OBJS)

fclean: clean
		$(REMOVE) $(NAME)

re: fclean all

.PHONY:	all clean fclean re