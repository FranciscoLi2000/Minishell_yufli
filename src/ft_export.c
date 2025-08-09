#include "../include/minishell.h"

int	ft_export(t_shell *sh, t_command *cmd)
{
	char	*eq;
	int		i;

	if (!cmd->argv[1])
	{
		ft_putendl_fd("minishell: export: missing argument", 2);
		return (1);
	}
	i = 1;
	while (cmd->argv[i])
	{
		eq = ft_strchr(cmd->argv[i], '=');
		if (!eq)
		{
			ft_putendl_fd("minishell: export: invalid format", 2);
			return (1);
		}
		*eq = '\0';
		set_env_var(sh, cmd->argv[i], eq + 1);
		*eq = '=';
		i++;
	}
	return (0);
}
