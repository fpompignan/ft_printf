
NAME = libftprintf.a

SRC = srcs/ft_printf.c srcs/utils.c

FILEO = {SRC:.c=.o}

WWW = -Wall -Wextra -Werror

${NAME}:
	gcc ${WWW} -c ${SRC} -I ./include	
	ar rc ${NAME} ft_printf.o utils.o
	ranlib ${NAME}

all: ${NAME}

clean:
	rm -f ft_printf.o utils.o

fclean: clean
	rm -f ${NAME}

re: fclean ${NAME}

.PHONY: all clean fclean re
