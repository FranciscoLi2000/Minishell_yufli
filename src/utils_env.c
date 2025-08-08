#include "../include/minishell.h"

char	*get_env_var(t_shell *sh, const char *name)
{
	(void)sh;
	(void)name;
	return (NULL);
}

int	set_env_var(t_shell *sh, const char *name, const char *value)
{
	(void)sh;
	(void)name;
	(void)value;
	return (0);
}

int	unset_env_var(t_shell *sh, const char *name)
{
	(void)sh;
	(void)name;
	return (0);
}
