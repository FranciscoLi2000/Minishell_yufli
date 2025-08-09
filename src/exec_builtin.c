#include "../include/minishell.h"

static int	is_builtin(char *cmd)
{
	if (!cmd)
		return (0);
	return (!ft_strcmp(cmd, "echo")
		|| !ft_strcmp(cmd, "cd")
		|| !ft_strcmp(cmd, "pwd")
		|| !ft_strcmp(cmd, "export")
		|| !ft_strcmp(cmd, "unset")
		|| !ft_strcmp(cmd, "env")
		|| !ft_strcmp(cmd, "exit"));
}

int	exec_builtin(t_shell *sh, t_command *cmd)
{
	if (!cmd || !cmd->argv || !cmd->argv[0])
		return (0);
	if (!ft_strcmp(cmd->argv[0], "echo"))
		return (ft_echo(cmd), 1);
	if (!ft_strcmp(cmd->argv[0], "cd"))
		return (sh->last_status = ft_cd(sh, cmd), 1);
	if (!ft_strcmp(cmd->argv[0], "pwd"))
		return (sh->last_status = ft_pwd(), 1);
	if (!ft_strcmp(cmd->argv[0], "export"))
		return (sh->last_status = ft_export(sh, cmd), 1);
	if (!ft_strcmp(cmd->argv[0], "unset"))
		return (sh->last_status = ft_unset(sh, cmd), 1);
	if (!ft_strcmp(cmd->argv[0], "env"))
		return (sh->last_status = ft_env(sh), 1);
	if (!ft_strcmp(cmd->argv[0], "exit"))
		return (ft_exit(sh, cmd), 1);
	return (0);
}
