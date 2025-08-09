#include "../include/minishell.h"

int	ft_cd(t_shell *sh, t_command *cmd)
{
	const char	*path;

	if (!cmd->argv[1])
	{
		path = get_env_var(sh, "HOME");
		if (!path)
		{
			ft_putstr("minishell: cd: HOME not set\n");
			return (1);
		}
	}
	else
		path = cmd->argv[1];
	if (chdir(path) != 0)
	{
		perror("minishell: cd");
		return (1);
	}
	return (0);
}
