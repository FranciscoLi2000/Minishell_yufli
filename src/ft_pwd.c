#include "../include/minishell.h"

int	ft_pwd(void)
{
	char	cwd[1024];

	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		write(1, cwd, ft_strlen(cwd));
		ft_putchar('\n');
		return (0);
	}
	else
	{
		perror("minishell: pwd");
		return (1);
	}
}
