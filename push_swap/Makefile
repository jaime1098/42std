NAME = push_swap

SRCS =	push_swap.c ft_swap.c ft_push.c ft_rotate.c  ft_rrotate.c \
		push_swap_utils.c order.c

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
	make -C libft/ fclean

fclean: clean
	$(REMOVE) $(NAME)

clear:
	clear

run: re clear
	./$(NAME) "9 7 8 4 6 3 5 2 1"

wc: re clear
	./$(NAME) "9 7 8 4 6 3 5 2 1" | wc -l

n: clear
	norminette

v: re clear
	bash ./../pocho_tester/push_swap_test.sh -v 100

re: fclean all clear