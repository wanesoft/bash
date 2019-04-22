/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signals.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 00:30:39 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/04/10 17:31:04 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"
//
//static void	give_back_the_prompt(int sig)
//{
//	if (sig == SIGINT)
//	{
//		rl_on_new_line();
//		rl_redisplay();
//		rl_cleanup_after_signal();
//	}
//	else if (sig == SIGQUIT)
//	{
//		exit(0);
//	}
//}
//
//void		handle_signals(void)
//{
//	signal(SIGINT, give_back_the_prompt);
//	signal(SIGQUIT, give_back_the_prompt);
//}

extern char			g_str[B_SIZE];
extern int			g_j;
extern int			g_pos;

void				ft_main_sig(int signo)
{
	if (signo == SIGINT)
	{
		ft_putstr_fd("\n\033[36mWelcome>\033[0m", 1);
		ft_bzero(g_str, B_SIZE);
//		g_str[0] = '\0';
		g_j = 0;
		g_pos = 0;
		ft_hello_mess(g_str);
		signal(SIGINT, ft_main_sig);
	}
}

void				ft_proc_sig(int signo)
{
	if (signo == SIGINT)
	{
		ft_putstr_fd("\n\033[31mabort\033[0m\n", 1);
		signal(SIGINT, ft_proc_sig);
	}
}
