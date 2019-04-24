/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 15:30:50 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/04/24 17:30:23 by ggwin-go         ###   ########.fr       */
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
	t_list 			*head;
	char			**env;
	struct termios	old;
//	t_ev			*ev;
//	t_ev			*trash;

	(void)ac;
	(void)av;
//	ev = NULL;
	env = copy_env(source_env);
	head = get_list_of_bins(env);
	fill_g_commands(head);
	tcgetattr(STDIN_FILENO, &old);
//	ft_init_ev(&ev, source_env);
	ft_init_screen();
	while (1)
	{
		if (!read_input(&head, &env))
			break ;
	}
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
	ft_lstdel(&head);
	ft_free_char_arr(&g_commands);
	exit(0);
}
