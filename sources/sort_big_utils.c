/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 19:26:32 by bpouchep          #+#    #+#             */
/*   Updated: 2022/01/20 19:26:45 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	try_push_next(t_dlst **a, t_dlst **b, int swap)
{
	int	b_size;

	b_size = ft_dlstsize(*b);
	if ((*b)->data == b_size - 2 && !swap)
	{
		pa(a, b, 1);
		return (1);
	}
	return (0);
}

int	smart_rotate_b(t_dlst **a, t_dlst **b)
{
	int		move_cnt;
	int		swap;
	int		b_size;
	t_dlst	*tmp;

	move_cnt = 0;
	swap = 0;
	b_size = ft_dlstsize(*b);
	tmp = *b;
	while (tmp->data != b_size - 1 && ++move_cnt)
		tmp = tmp->next;
	while ((*b)->data != b_size - 1)
	{
		if (!try_push_next(a, b, swap))
		{
			if (move_cnt > b_size / 2)
				rrb(b, 1);
			else
				rb(b, 1);
		}
		else
			swap = 1;
		}
	return (swap);
}
