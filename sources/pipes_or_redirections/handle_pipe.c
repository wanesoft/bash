/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 13:42:48 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/04/24 18:51:42 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

char				**g_commands;

static int	print_error_command(char *s)
{
	ft_putstr("21sh: command not found: ");
	ft_putendl(s);
	return (1);
}

int	ft_call_exec(char *path, char **split, char **env)
{
	pid_t	my_pid;

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

void	ft_call_functions(char **split, char ***env)
{
	if (ft_strequ(split[0], "exit"))
		exit(EXIT_SUCCESS);
	else if (ft_strchr(split[0], '/'))
		ft_call_exec(split[0], split, *env);
	else
		print_error_command(split[0]);
}

int		handle_pipe(char **s1, char **s2, char **res, char **env)
{
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (pipe(pipefd) < 0)
	{
		ft_putstr("Error with pipe() in ");
		perror(*s1);
		exit(1);
	}
	if ((pid1 = fork()) == 0)
	{
		dup2(pipefd[FD_FOR_WRITE], STDOUT_FILENO);
		close(pipefd[FD_FOR_READ]);
		ft_call_functions(s1, &env);
		return (1);
	}
	if ((pid2 = fork()) == 0)
	{
		dup2(pipefd[FD_FOR_READ], STDIN_FILENO);
		close(pipefd[FD_FOR_WRITE]);
		ft_call_functions(s2, &env);
		return (1);
	}
	close(pipefd[FD_FOR_READ]);
	close(pipefd[FD_FOR_WRITE]);
	wait(NULL);
	waitpid(pid2, NULL, 0);
	return (1);
}

int     main(int ac, char **av, char **source_env)
{
	char	*s1[] = {"/bin/ls", "-lh", NULL};
	// char	*s2[] = {"/usr/bin/wc", "-l", NULL};
	char	*s2[] = {"/bin/cat", "-e", NULL};
	char	*res;
	t_list	*head;
	char	**env;

	res = NULL;
	(void)ac;
	(void)av;
	env = copy_env(source_env);
	head = get_list_of_bins(env);
	fill_g_commands(head);
	// printf("%s\n", res);
    handle_pipe(s1, s2, &res, env);
	// printf("\n%s\n", res);
    return (0);
}
