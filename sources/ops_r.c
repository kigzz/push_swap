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

static int	rotate(t_dlst **dlst, int rev)
{
	t_dlst	*tmp;

	if (!*dlst || ft_dlstsize(*dlst) < 2)
		return (1);
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
	return (0);
}

void	ra(t_dlst **dlst, int print)
{
	if (rotate(dlst, 0))
		return ;
	if (print)
		write(1, "ra\n", 3);
}

void	rb(t_dlst **dlst, int print)
{
	if (rotate(dlst, 0))
		return ;
	if (print)
		write(1, "rb\n", 3);
}

void	rra(t_dlst **dlst, int print)
{
	if (rotate(dlst, 1))
		return ;
	if (print)
		write(1, "rra\n", 4);
}

void	rrb(t_dlst **dlst, int print)
{
	if (rotate(dlst, 1))
		return ;
	if (print)
		write(1, "rrb\n", 4);
}
