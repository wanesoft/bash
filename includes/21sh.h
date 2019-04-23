/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21sh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 15:48:37 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/04/24 00:56:08 by ggwin-go         ###   ########.fr       */
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
# include <sys/termios.h>
# include <curses.h>
# include <term.h>

# include <sys/ioctl.h>

# define BUF_SIZE		256
# define B_SIZE			1024
# define TESTTT			1

# define K_SPACE		32
# define K_ESC			27
# define K_Q			113
# define K_DOWN			4348699
# define K_UP			4283163
# define K_RIGHT		4414235
# define K_LEFT			4479771
# define K_ENTER		10
# define K_DEL			2117294875
# define K_BACKSP		127
# define K_HOME			4741915
# define K_END			4610843

extern char		**g_commands;

typedef struct	s_exec
{
	char			*name;
	char			*path;
	struct s_exec	*next;
}				t_exec;

char			**copy_env(char **env);

int				read_input(t_list **head, char ***env);

char			**spec_split(char *s, char **env);

char			**divide_commands(char *s);

void			call_functions(char **split, char ***env, t_list **head);

int				ft_cd(char **av, char ***env);
int				ft_echo(char **av);
int				ft_env(char **av, char **env);
int				ft_hash(t_list *head);
int				ft_setenv(char **av, char ***env, t_list **head);
int				ft_unsetenv(char **av, char ***env, t_list **head);

char			**get_args(void);
char			*replace_variable(char *str, char **env);
char			*replace_tilde(char *av, char **env,
											int *has_replaceable_tilda);

void			handle_signals(void);

t_list			*get_list_of_bins(char **env);

void			fill_g_commands(t_list *head);
char			*commands_generator(const char *text, int state);
char			**commands_completion(const char *text, int start, int end);

void			ft_init_screen(void);
char			*ft_new_while(void);
//void			ft_autocompl(t_ev *ev, char str[B_SIZE], int *j);
void			ft_autocompl(char str[B_SIZE], int *j);
void			ft_back_screen(struct termios *old);
void			ft_push_ev(char *key, char **val);
void			ft_del_arr(char **arr);
void			ft_init_ev(char **env);
int				ft_count_arr(char **arr);
void			ft_main_sig(int signo);
void			ft_proc_sig(int signo);
void			ft_hello_mess(char *str);

#endif
