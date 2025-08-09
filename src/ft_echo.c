#include "../include/minishell.h"

int	ft_echo(t_command *cmd)
{
	int	i;
	int	n_flag;

	i = 1;
	n_flag = 0;
	if (cmd->argv[1] && !ft_strcmp(cmd->argv[1], "-n"))
	{
		n_flag = 1;
		i++;
	}
	while (cmd->argv[i])
	{
		write(1, cmd->argv[i], ft_strlen(cmd->argv[i]));
		if (cmd->argv[i + 1])
			ft_putchar(' ');
		i++;
	}
	if (!n_flag)
		ft_putchar('\n');
	return (0);
}
