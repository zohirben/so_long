CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = get_next_line_utils.c get_next_line.c
OBJS = ${SRCS:.c=.o}
NAME = gnl.a
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