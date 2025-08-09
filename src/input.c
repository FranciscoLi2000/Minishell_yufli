#include "../include/minishell.h"

void	read_input(t_shell *sh, char **line)
{
	char	buffer[BUFFER_SIZE];
	ssize_t	bytes;
	int		i;

	(void)sh;
	ft_putstr("minishell$ ");
	i = 0;
	bytes = read(0, buffer, BUFFER_SIZE - 1);
	if (bytes <= 0)
	{
		*line = NULL;
		return ;
	}
	buffer[bytes] = '\0';
	while (buffer[i] && buffer[i] != '\n')
		i++;
	buffer[i] = '\0';
	*line = ft_strdup(buffer);
}
