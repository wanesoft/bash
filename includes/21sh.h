/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21sh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 15:48:37 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/04/06 18:30:55 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "ft_vector.h"
# include "ft_avl_tree_str.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <stdio.h>
# include <dirent.h>
# include <signal.h>
# include <pwd.h>
# include <readline/readline.h>
# include <readline/history.h>

# include <sys/ioctl.h>

# define BUF_SIZE 256

// char	**g_commands;

typedef struct	s_exec
{
	char			*name;
	char			*path;
	struct s_exec	*next;
}				t_exec;

t_avl_node		*ft_bins_from_env(char **env);
char			**copy_env(char **env);

int				read_input(t_avl_node **root, char ***env);

char			**spec_split(char *s, char **env);

char			**divide_commands(char **s);

int				ft_cd(char **av, char ***env);
int				ft_echo(char **av);
int				ft_env(char **av, char **env);
int				ft_hash(t_avl_node *root);
int				ft_setenv(char **av, char ***env, t_avl_node **root);
int				ft_unsetenv(char **av, char ***env, t_avl_node **root);

char			**get_args(void);
char			*replace_variable(char *str, char **env);
char			*replace_tilde(char *av, char **env,
											int *has_replaceable_tilda);

void			handle_signals(void);

void			fill_g_commands(t_avl_node *root);
char			*commands_generator(const char *text, int state);
char			**commands_completion(const char *text, int start, int end);

#endif
