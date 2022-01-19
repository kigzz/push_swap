/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_r.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:42:55 by bpouchep          #+#    #+#             */
/*   Updated: 2022/01/19 15:43:09 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotate(t_dlist **dlst, int rev)
{
	t_dlist	*tmp;

	if (!*dlst || ft_dlstsize(*dlst) < 2)
		return ;
	if (rev == 0)
	{
		tmp = ft_dlstfirst(*dlst);
		*dlst = (*dlst)->next;
		ft_dlstadd_back(dlst, tmp);
		tmp->next = NULL;
		(*dlst)->prev = NULL;
	}
	if (rev != 0)
	{
		tmp = ft_dlstlast(*dlst);
		tmp->prev->next = NULL;
		ft_dlstadd_front(dlst, tmp);
		tmp->prev = NULL;
	}
}

void	ra(t_dlist **dlst, int print)
{
	rotate(dlst, 0);
	if (print)
		write(1, "ra\n", 3);
}

void	rb(t_dlist **dlst, int print)
{
	rotate(dlst, 0);
	if (print)
		write(1, "rb\n", 3);
}

void	rra(t_dlist **dlst, int print)
{
	rotate(dlst, 1);
	if (print)
		write(1, "rra\n", 4);
}

void	rrb(t_dlist **dlst, int print)
{
	rotate(dlst, 1);
	if (print)
		write(1, "rrb\n", 4);
}
