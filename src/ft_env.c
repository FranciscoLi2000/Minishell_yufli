#include "../include/minishell.h"

int	ft_env(t_shell *sh)
{
	int	i;

	i = 0;
	while (sh->env[i])
	{
		write(1, sh->env[i], ft_strlen(sh->env[i]));
		ft_putchar('\n');
		i++;
	}
	return (0);
}
