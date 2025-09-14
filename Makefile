NAME		= minishell

SRC		= \
		exec_builtin.c ft_echo.c ft_export.c ft_unset.c output.c \
		redirect.c utils_env.c exec_external.c ft_env.c ft_putendl_fd.c \
		input.c parse.c signal.c utils_string.c ft_cd.c \
		ft_exit.c ft_pwd.c main.c pipe.c tokenize.c

SRCS		= ${addprefix ${PRE}, ${SRC}}

OBJS		= ${SRCS:.c=.o}

PRE		= ./srcs/
HEAD		= ./includes/

RM		= rm -f

CC		= cc
CFLAGS		= -Wall -Wextra -Werror

all: ${NAME}

.c.o:
	${CC} ${CFLAGS} -c -I ${HEAD} $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
