/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 22:36:40 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/04/22 00:25:25 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

static	int		write_to_file(int fd, char *path, char **av, char **env)
{
	(void)av;
	(void)env;
	ft_putendl("Write to file:");
	write(fd, path, ft_strlen(path));
	return (0);
}

static	int		read_from_file(int fd, char *path, char **av, char **env)
{
	ssize_t		ret;
	char		*s;
	char		buf[BUF_SIZE + 1];

	(void)av;
	(void)env;
	(void)path;
	ft_putendl("Read from file:");
	s = ft_strnew(0);
	while ((ret = read(fd, buf, BUF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		s = ft_strjoin_free(s, buf, 1);
	}
	ft_putendl(s);
	return (0);
}

int				handle_redirections(char *filename, char *direct,
									char *path, char **av, char **env)
{
	int fd;
	// int ret;
	++direct;
	if (*direct == '>')
	{
		if (*(direct + 1) == '>')
			fd = open(filename, O_CREAT | O_APPEND | O_WRONLY, 644);
		else
			fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 644);
	}
	else
	{
		fd = open(filename, O_CREAT | O_APPEND | O_RDONLY);
	}	
	if (fd < 0)
	{
		perror("open");
		exit(1);
	}
	// ret = dup2(fd, 1);
	if (*direct == '>')
		write_to_file(fd, path, av, env);
	else
		read_from_file(fd, path, av, env);
	// if (ret < 0)
	// {
	// 	perror("dup2");
	// 	exit(1);
	// }
	// call_exec(path, av, env);
	close(fd);
	return (1);
}

int				main(int ac, char **av, char **env)
{
	if (ac > 3)
	{
		(void)av;
		(void)env;
		++av;
		handle_redirections(*av, *(av + 1), *(av + 2), av + 2, env);
	}
	return (0);
}