/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 22:41:23 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/04/18 16:53:10 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

static int	print_error_command(char *s)
{
	ft_putstr("21sh: command not found: ");
	ft_putendl(s);
	return (1);
}

int	call_exec(char *path, char **split, char **env)
{
	pid_t	my_pid;

	signal(SIGINT, ft_proc_sig); //rewrite ivan
	if (!access(path, X_OK))
	{
		my_pid = fork();
		if (my_pid > 0)
			wait(NULL);
		if (my_pid == 0)
			execve(path, split, env);
	}
	else
	{
		ft_putstr("21sh: permission denied: ");
		ft_putendl(path);
	}
	return (1);
}

void	call_functions(char **split, char ***env, t_avl_node **root)
{
	t_avl_node	*node;

	if (ft_strequ(split[0], "exit"))
		exit(EXIT_SUCCESS);
	else if (ft_strequ(split[0], "cd"))
		ft_cd(split + 1, env);
	else if (ft_strequ(split[0], "echo"))
		ft_echo(split + 1);
	else if (ft_strequ(split[0], "env"))
		ft_env(split + 1, *env);
	else if (ft_strequ(split[0], "setenv"))
		ft_setenv(split + 1, env, root);
	else if (ft_strequ(split[0], "unsetenv"))
		ft_unsetenv(split + 1, env, root);
	else if (ft_strequ(split[0], "hash"))
		ft_hash(*root);
	else if ((node = ft_avl_search(*root, split[0])))
		call_exec(node->path, split, *env);
	else if (ft_strchr(split[0], '/'))
		call_exec(split[0], split, *env);
	else
		print_error_command(split[0]);
}

