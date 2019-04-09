/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_screen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draynor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:47:31 by draynor           #+#    #+#             */
/*   Updated: 2019/03/02 17:47:37 by draynor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void				ft_init_screen(void)
{
	struct termios	new;

	tcgetattr(STDIN_FILENO, &new);
	new.c_lflag &= ~(ICANON);
	new.c_lflag &= ~(ECHO);
	new.c_cc[VMIN] = 1;
	new.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSADRAIN, &new);
	tgetent(getenv("TERM"), NULL);
	ft_putstr_fd(tgetstr("ti", NULL), TESTTT);
	ft_putstr_fd(tgetstr("vi", NULL), TESTTT);
}
