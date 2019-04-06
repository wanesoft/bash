/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 15:30:50 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/04/07 00:18:16 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

/*
**int		access(const char *path, int mode);
**char		*getcwd(char *buf, size_t size);
**int		chdir(const char *path);
**int		fstat(int fildes, struct stat *buf);
**int		lstat(const char *restrict path, struct stat *restrict buf);
**int		stat(const char *restrict path, struct stat *restrict buf);
**sig_t		signal(int sig, sig_t func);
*/

int		main(int ac, char **av, char **source_env)
{
	t_avl_node	*root;
	char		**env;

	(void)ac;
	(void)av;
	// rl_attempted_completion_function = commands_completion;
	env = copy_env(source_env);
	root = ft_bins_from_env(env);
	// fill_g_commands(root);
	while (1)
	{
		if (!read_input(&root, &env))
			break ;
	}
	ft_avl_iter_post_order(root, &ft_avl_free_node);
	return (0);
}
