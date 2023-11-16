NAME = libftprintf.a

SRCS = ft_printf.c ft_isc.c ft_isid.c ft_isp.c ft_iss.c ft_isu.c ft_isxX.c

OBJS = ${SRCS:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror
REMOVE = rm -f

all: ${NAME}

${NAME}: ${OBJS}
		 ar rcs ${NAME} ${OBJS}

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean: 
	${REMOVE} ${OBJS}

fclean: clean
		${REMOVE} ${NAME}

re: fclean all

.PHONY:	all clean fclean re