# ========= CONFIG ============
NAME		= minishell

CC		= cc
CFLAGS		= -Wall -Wextra -Werror

SRC		= src/main.c src/input.c src/tokenize.c src/parse.c \
		src/exec_builtin.c src/exec_external.c src/redirect.c \
		src/pipe.c src/signal.c src/utils_string.c src/utils_env.c

OBJ		= $(SRC:.c=.o)

INCLUDE		= -I include/

# ========= RULES =============
all: $(NAME)

# pipex 的最终链接目标
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(INCLUDE) -o $(NAME)

# ========= CLEANING ==========
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

# ========= PHONY RULES ========
.PHONY: all clean fclean re
