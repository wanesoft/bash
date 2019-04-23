/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 22:41:23 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/04/24 00:12:09 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

static int		print_error_command(char *s)
{
	ft_putstr("21sh: command not found: ");
	ft_putendl(s);
	return (1);
}

static int		call_exec(char *path, char **split, char **env)
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

static t_list	*search_command(t_list *head, char *name)
{
	char	*tmp;

	tmp = ft_strchr(name, '/');
	if (!tmp)
		tmp = name;
	while (head)
	{
		if (ft_strequ(tmp, head->name))
			break ;
		head = head->next;
	}
	if (head)
		return (head);
	return (NULL);
}

void			call_functions(char **split, char ***env, t_list **head)
{
	t_list *tmp;

	if (ft_strequ(split[0], "exit"))
		exit(EXIT_SUCCESS);
	else if (ft_strequ(split[0], "cd"))
		ft_cd(split + 1, env);
	else if (ft_strequ(split[0], "echo"))
		ft_echo(split + 1);
	else if (ft_strequ(split[0], "env"))
		ft_env(split + 1, *env);
	else if (ft_strequ(split[0], "setenv"))
		ft_setenv(split + 1, env, head);
	else if (ft_strequ(split[0], "unsetenv"))
		ft_unsetenv(split + 1, env, head);
	else if (ft_strequ(split[0], "hash"))
		ft_hash(*head);
	else if ((tmp = search_command(*head, split[0])))
		call_exec(tmp->path, split, *env);
	else if (ft_strchr(split[0], '/'))
		call_exec(split[0], split, *env);
	else
		print_error_command(split[0]);
}

