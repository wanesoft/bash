/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 13:42:48 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/04/23 18:17:44 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

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
	ssize_t	rd;
	char	buf[BUF_SIZE + 1];
	char	*response;
	int		fd[2];

	if (pipe(fd) < 0)
	{
		ft_putstr("Error with pipe() in ");
		perror(*s1);
		exit(1);
	}
	response = NULL;
	printf("\nFirst command:\n\n");
	dup2(STDOUT_FILENO, fd[1]);
	close(STDOUT_FILENO);
	ft_call_functions(s1, &env);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	printf("\nSecond command:\n\n");
	while ((rd = read(fd[0], buf, BUF_SIZE)))
	{
		buf[rd] = '\0';
		response = ft_strjoin_free(response, buf, 1);
	}
	close(fd[0]);
	// ft_putstr(response);
	*res = response;
	ft_call_functions(s2, &env);
	return (1);
}

int     main(int ac, char **av, char **env)
{
	char	*s1[4] = {"/bin/cat", "author", NULL};
	// char	*s1[4] = {"/bin/ls", ".", NULL};
	char	*s2[4] = {"/bin/ls", ".", NULL};
	char	*res;

	res = NULL;
	(void)ac;
	(void)av;
	printf("%s\n", res);
    handle_pipe(s1, s2, &res, env);
	printf("\n%s\n", res);
    return (0);
}
