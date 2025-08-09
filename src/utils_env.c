#include "../include/minishell.h"

char	*get_env_var(t_shell *sh, const char *name)
{
	int	i;
	int	len;

	len = ft_strlen(name);
	i = 0;
	while (sh->env[i])
	{
		if (!ft_strncmp(sh->env[i], name, len) && sh->env[i][len] == '=')
			return (sh->env[i] + len + 1);
		i++;
	}
	return (NULL);
}

static int	append_env_var(t_shell *sh, char *new_var)
{
	int		i;
	char	**new_env;

	i = 0;
	while (sh->env[i])
		i++;
	new_env = malloc(sizeof(char *) * (i + 2));
	if (!new_env)
		return (1);
	i = 0;
	while (sh->env[i])
	{
		new_env[i] = sh->env[i];
		i++;
	}
	new_env[i] = new_var;
	new_env[i + 1] = NULL;
	free(sh->env);
	sh->env = new_env;
	return (0);
}

int	set_env_var(t_shell *sh, const char *name, const char *value)
{
	int		i;
	int		len;
	char	*new_var;

	len = ft_strlen(name);
	new_var = malloc(len + ft_strlen(value) + 2);
	if (!new_var)
		return (1);
	ft_strcpy(new_var, name);
	new_var[len] = '=';
	ft_strcpy(new_var + len + 1, value);
	i = 0;
	while (sh->env[i])
	{
		if (!ft_strncmp(sh->env[i], name, len) && sh->env[i][len] == '=')
		{
			free(sh->env[i]);
			sh->env[i] = new_var;
			return (0);
		}
		i++;
	}
	return (append_env_var(sh, new_var));
}

int	unset_env_var(t_shell *sh, const char *name)
{
	int		i;
	int		j;
	int		len;

	len = ft_strlen(name);
	i = 0;
	while (sh->env[i])
	{
		if (!ft_strncmp(sh->env[i], name, len) && sh->env[i][len] == '=')
		{
			free(sh->env[i]);
			j = i;
			while (sh->env[j])
			{
				sh->env[j] = sh->env[j + 1];
				j++;
			}
			return (0);
		}
		i++;
	}
	return (0);
}
