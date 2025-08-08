#include "../include/minishell.h"

t_command	**parse_commands(char **tokens)
{
	t_command	**cmds;

	(void)tokens;
	cmds = (t_command **)malloc(sizeof(t_command *) * 1);
	if (!cmds)
		return (NULL);
	cmds[0] = NULL;
	return (cmds);
}
