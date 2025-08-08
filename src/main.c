#include "../include/minishell.h"

static void	init_shell(t_shell *sh, char **envp)
{
	int	i;
	int	len;

	i = 0;
	while (envp[i])
		i++;
	sh->env = (char **)malloc(sizeof(char *) * (i + 1));
	len = 0;
	while (len < i)
	{
		sh->env[len] = ft_strdup(envp[len]);
		len++;
	}
	sh->env[len] = NULL;
	sh->last_status = 0;
}

int	main(int argc, char **argv, char **envp)
{
	t_shell		sh;
	char		*line;
	char		**tokens;
	t_command	**cmds;

	(void)argc;
	(void)argv;
	init_shell(&sh, envp);
	handle_signal_parent();
	while (1)
	{
		read_input(&sh, &line);
		if (!line)
			break ;
		tokens = tokenize(line);
		cmds = parse_commands(tokens);
		handle_pipes(&sh, cmds);
		free(line);
	}
	return (0);
}
