/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 16:03:53 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/04/07 00:17:34 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

/*
**static char	*get_input_str(void)
**{
**	size_t	i;
**	size_t	buf_size;
**	char	*buf;
**	char	c;
**
**	i = 0;
**	buf_size = BUF_SIZE;
**	buf = ft_strnew(buf_size);
**	ft_putstr_len("$> ", 3);
**	while (1)
**	{
**		c = getchar();
**		if (c == '\n')
**			break ;
**		else if (c == '\t')
**			ft_putendl("Youhoo");
**		buf[i++] = c;
**		buf[i] = '\0';
**		if (i == buf_size)
**		{
**			buf_size *= 2;
**			buf = ft_realloc(buf, buf_size);
**		}
**	}
**	return (buf);
**}
*/

static char	*get_input_str(void)
{
	char	*buf;

	while (1)
	{
		buf = readline("$> ");
		if (!buf)
			break ;
		if (ft_strlen(buf))
		{
			add_history(buf);
			return (ft_strdup(buf));
		}
		free(buf);
	}
	return (NULL);
}

static int	print_error_command(char *s)
{
	ft_putstr("minishell: command not found: ");
	ft_putendl(s);
	return (1);
}

static int	call_exec(char *path, char **split, char **env)
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
		ft_putstr("minishell: permission denied: ");
		ft_putendl(path);
	}
	return (1);
}

static void	call_functions(char **split, char ***env, t_avl_node **root)
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
	// else if (ft_strequ(split[0], "hash"))
	// 	ft_hash(*root);
	else if ((node = ft_avl_search(*root, split[0])))
		call_exec(node->path, split, *env);
	else if (ft_strchr(split[0], '/'))
		call_exec(split[0], split, *env);
	else
		print_error_command(split[0]);
}

int			read_input(t_avl_node **root, char ***env)
{
	char		**commands;
	char		**split;
	char		**tmp;
	char		*input_str;

	handle_signals();
	input_str = get_input_str();
	commands = divide_commands(&input_str);
	tmp = commands;
	if (tmp)
	{
		while (*tmp)
		{
			split = spec_split(replace_variable(*tmp, *env), *env);
			if (!split)
				break ;
			if (split[0])
				call_functions(split, env, root);
			ft_free_char_arr(&split);
			tmp++;
		}
		free(commands);
	}
	return (1);
}
