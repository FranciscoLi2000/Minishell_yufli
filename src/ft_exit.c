#include "../include/minishell.h"

int	ft_exit(t_shell *sh, t_command *cmd)
{
	(void)sh;
	ft_putstr("exit\n");
	if (cmd->argv[1])
		exit(ft_atoi(cmd->argv[1]));
	exit(0);
}
