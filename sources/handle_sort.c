/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 01:53:19 by bpouchep          #+#    #+#             */
/*   Updated: 2022/01/20 01:53:30 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	is_sorted(t_dlst *dlst)
{
	while (dlst->next != NULL)
	{
		if (dlst->data > dlst->next->data)
			return (0);
		dlst = dlst->next;
	}
	return (1);
}

void	handle_sort(t_dlst **a, t_dlst **b, int n_cnt)
{
	if (n_cnt < 2 || is_sorted(*a))
		return ;
	if (n_cnt <= 5)
		sort_small(a, b, n_cnt);
	else
		sort_big(a, b, n_cnt);
}
