#ifndef MINISHELL_H
# define MINISHELL_H

# define BUFFER_SIZE 1024

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <signal.h>
# include <errno.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/wait.h>

typedef struct s_command
{
	char	**argv;
	char	*infile;
	char	*outfile;
	int		append;
}	t_command;

typedef struct s_shell
{
	char	**env;
	int		last_status;
}	t_shell;

void	read_input(t_shell *sh, char **line);

/* syntax analyze */
char	**tokenize(char *line);

/* commands structure analyze */
t_command	**parse_commands(char **tokens);

/* Shell built-in commands */
int		exec_builtin(t_shell *sh, t_command *cmd);

/* Shell external commands */
void	exec_external(t_shell *sh, t_command *cmd);

/* redirection handle */
void	handle_redirect(t_command *cmd);

/* pipes handle */
void	handle_pipes(t_shell *sh, t_command **cmds);

/* signal parse */
void	handle_signal_parent(void);
void	handle_signal_child(void);

/* strings handle */
char	*ft_strdup(const char *src);
int		ft_strcmp(const char *s1, const char *s2);

/* Environment Variable parse */
char	*get_env_var(t_shell *sh, const char *name);
int		set_env_var(t_shell *sh, const char *name, const char *value);
int		unset_env_var(t_shell *sh, const char *name);

#endif
