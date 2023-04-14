CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c ft_print_numbers.c ft_print_strs.c
OBJS = ${SRCS:.c=.o}
NAME = libftprintf.a
AR = ar -rcs

all:${NAME}

%.o:%.c
	$(CC) $(CFLAGS) -o $@ -c $<

${NAME}:${OBJS}
	${AR} ${NAME} $^

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

re:	fclean all