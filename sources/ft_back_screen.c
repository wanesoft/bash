/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_back_screen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draynor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:46:07 by draynor           #+#    #+#             */
/*   Updated: 2019/03/02 17:47:18 by draynor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void				ft_back_screen(struct termios *old)
{
	tcsetattr(STDIN_FILENO, TCSANOW, old);
	ft_putstr_fd(tgetstr("te", NULL), TESTTT);
	ft_putstr_fd(tgetstr("ve", NULL), TESTTT);
	ft_putstr_fd("\033[0m", TESTTT);
}
