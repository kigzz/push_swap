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

static void	swap(t_dlist *dlst)
{
	t_dlist	tmp;

	if (ft_dlstsize(dlst) < 2)
		return ;
	tmp.data = (dlst->next)->data;
	(dlst->next)->data = dlst->data;
	dlst->data = tmp.data;
}

void	sa(t_dlist *a, int print)
{
	swap(a);
	if (print)
		write(1, "sa\n", 3);
}

void	sb(t_dlist *a, int print)
{
	swap(a);
	if (print)
		write(1, "sb\n", 3);
}
