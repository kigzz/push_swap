/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_r.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 02:27:57 by bpouchep          #+#    #+#             */
/*   Updated: 2022/01/19 02:28:08 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap(t_dlst **dlst)
{
	int	sz;

	sz = ft_dlstsize(*dlst);
	if (!*dlst)
		return ;
	if (sz < 2)
		return ;
	if (sz == 2)
	{
		(*dlst)->next->next = *dlst;
		*dlst = (*dlst)->next;
		(*dlst)->next->next = NULL;
		(*dlst)->prev = NULL;
		(*dlst)->next->prev = *dlst;
	}
	else
	{
		(*dlst)->next = (*dlst)->next->next;
		(*dlst)->next->prev->next = *dlst;
		(*dlst)->prev = (*dlst)->next->prev;
		(*dlst)->next->prev->prev = NULL;
		(*dlst)->next->prev = *dlst;
		*dlst = (*dlst)->prev;
	}
}

void	sa(t_dlst **a, int print)
{
	swap(a);
	if (print)
		write(1, "sa\n", 3);
}

void	sb(t_dlst **b, int print)
{
	swap(b);
	if (print)
		write(1, "sb\n", 3);
}

void	ss(t_dlst **a, t_dlst **b, int print)
{
	swap(a);
	swap(b);
	if (print)
		write (1, "ss\n", 3);
}
