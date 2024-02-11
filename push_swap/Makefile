NAME = push_swap

SRCS =	push_swap.c

OBJECTS = $(SRCS:.c=.o)

CFLAGS := -Wall -Wextra -Werror
REMOVE = rm -f
CC := cc

all: $(NAME)

$(NAME): $(OBJECTS) libft/libft.a
	$(CC) $(OBJECTS) libft/libft.a -o $(NAME)

libft/libft.a:
	make -C libft/

.c.o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	$(REMOVE) $(OBJECTS)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all