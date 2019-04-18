/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 13:42:48 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/04/17 22:40:28 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int		handle_pape(char **s1, char **s2, char **res, char **env)
{
	pid_t	childe_pid;
	ssize_t	rd;
	char	buf[BUF_SIZE + 1];
	char	*response;
	int		fd[2];

	// 	call_exec(*s1, s1, env);
	// (void)s2;
	// (void)res;
	if (pipe(fd) < 0)
	{
		ft_putstr("Error with pipe() in ");
		perror(*s1);
		exit(1);
	}
	response = NULL;
	if ((childe_pid = fork()) == -1)
	{
		ft_putstr("Error with fork() in ");
		perror(*s1);
		exit(1);
	}
	if (childe_pid > 0)
	{
		wait(NULL);
		printf("\nChilde:\n\n");
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		call_exec(*s2, s2 + 1, env);
		// write(fd[1], *res, ft_strlen(*s1));
	}
	else
	{
		printf("\nParent:\n\n");
		dup2(fd[1], STDOUT_FILENO);
		// if (dup2(fd[1], STDOUT_FILENO) != STDOUT_FILENO)
		// {
		// 	ft_putstr("Error with dup2()");
		// 	perror(*s1);
		// 	exit(1);
		// }
		close(fd[1]);
		call_exec(*s1, s1 + 1, env);
		// response = ft_strnew(0);
		// while ((rd = read(fd[0], buf, BUF_SIZE)))
		// {
		// 	buf[rd] = '\0';
		// 	response = ft_strjoin_free(response, buf, 1);
		// }
		// ft_echo(&response);
	}
	// free(*res);
	// *res = response;
	return (1);
}

int     main(int ac, char **av, char **env)
{
	char	*s1[4] = {"/bin/ls", "ls", ".", NULL};
	char	*s2[4] = {"/bin/cat", "cat", NULL, NULL};
	char	*res;

	res = NULL;
	printf("%s\n", res);
    handle_pape(s1, s2, &res, env);
	printf("\n%s\n", res);
    return (0);
}