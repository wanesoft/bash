/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signals.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 00:30:39 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/04/01 21:06:07 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

static void	give_back_the_prompt(int sig)
{
	if (sig == SIGINT)
	{
		rl_on_new_line();
		rl_redisplay();
		rl_cleanup_after_signal();
	}
	else if (sig == SIGQUIT)
	{
		exit(0);
	}
}

void		handle_signals(void)
{
	signal(SIGINT, give_back_the_prompt);
	signal(SIGQUIT, give_back_the_prompt);
}
