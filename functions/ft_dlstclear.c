/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:32:56 by bpouchep          #+#    #+#             */
/*   Updated: 2022/01/15 15:33:04 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_dlstclear(t_dlist **dlst, void (*del)(void *))
{
	void	*prev;

	if (!dlst || !del)
		return ;
	while (*dlst)
	{
		del((*dlst)->data);
		prev = *dlst;
		*dlst = (*dlst)->next;
		free(prev);
	}
	*dlst = NULL;
}
