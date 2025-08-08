#include "../include/minishell.h"

char	**tokenize(char *line)
{
	char	**tokens;

	(void)line;
	tokens = (char **)malloc(sizeof(char *) * 1);
	if (!tokens)
		return (NULL);
	tokens[0] = NULL;
	return (tokens);
}
