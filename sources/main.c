/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 15:30:50 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/04/10 17:26:45 by ggwin-go         ###   ########.fr       */
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

char				**g_commands;

int					main(int ac, char **av, char **source_env)
{
	t_avl_node		*root;
	char			**env;
	struct termios	old;
//	t_ev			*ev;
//	t_ev			*trash;

	(void)ac;
	(void)av;
//	ev = NULL;
	env = copy_env(source_env);
	root = ft_bins_from_env(env);
	fill_g_commands(root);
	tcgetattr(STDIN_FILENO, &old);
//	ft_init_ev(&ev, source_env);
	ft_init_screen();
	while (1)
	{
		if (!read_input(&root, &env))
			break ;
	}
	ft_avl_iter_post_order(root, &ft_avl_free_node);
	ft_back_screen(&old);
	//free ev
//	while (ev)
//	{
//		trash = ev;
//		ft_del_arr(trash->val);
//		free(trash->val);
//		free(trash->key);
//		ev = ev->next;
//		free(trash);
//	}
	return (0);
}
