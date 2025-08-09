#include "../include/minishell.h"

int	ft_unset(t_shell *sh, t_command *cmd)
{
	int	i;

	if (!cmd->argv[1])
	{
		ft_putendl_fd("minishell: unset: missing argument", 2);
		return (1);
	}
	i = 1;
	while (cmd->argv[i])
	{
		unset_env_var(sh, cmd->argv[i]);
		i++;
	}
	return (0);
}
