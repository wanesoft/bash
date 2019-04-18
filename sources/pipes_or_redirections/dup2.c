/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 22:36:40 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/04/18 16:53:15 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int     handle_redirections(char *filename, char *path, char **av, char **env)
{
    int fd;
    int ret;

    fd = open(filename, O_CREAT | O_APPEND | O_WRONLY);
    if (fd < 0)
    {
        perror("open");
        exit(1);
    }
    ret = dup2(fd, 1);
    if (ret < 0)
    {
        perror("dup2");
        exit(1);
    }
    call_exec(path, av, env);
    close(fd);
    return (1);
}