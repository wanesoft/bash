/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 13:53:48 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/02/23 19:54:48 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst)
{
	if (!alst || !*alst)
		return ;
	if (*alst != NULL)
		ft_lstdel(&((*alst)->next));
	free((*alst)->content);
	free(*alst);
	*alst = NULL;
}
