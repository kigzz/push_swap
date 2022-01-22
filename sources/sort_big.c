/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 19:26:10 by bpouchep          #+#    #+#             */
/*   Updated: 2022/01/20 19:26:25 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push_in_chunks(t_dlst **a, t_dlst **b, int chunk_sz, int size)
{
	int	chunk_n;
	int	cnt;

	chunk_n = 1;
	cnt = 0;
	while (size > 0)
	{
		if ((*a)->data < (chunk_sz * chunk_n))
		{
			pb(a, b, 1);
			if ((*b)->data < (chunk_sz * chunk_n - chunk_sz / 2))
				rb(b, 1);
			cnt++;
			size--;
		}
		else
			ra(a, 1);
		if (cnt == chunk_sz * chunk_n)
			chunk_n++;
	}
}

static void	push_back_chunks(t_dlst **a, t_dlst **b)
{
	while (ft_dlstsize(*b))
	{
		if (smart_rotate_b(a, b))
		{
			pa(a, b, 1);
			if (ft_dlstsize(*b) > 1 && (*b)->data < (*b)->next->data)
				ss(a, b, 1);
			else
				sa(a, 1);
		}
		else
			pa(a, b, 1);
	}
}

void	sort_big(t_dlst **a, t_dlst **b, int size)
{
	int	chunk_sz;

	chunk_sz = size / 12 + 22;
	push_in_chunks(a, b, chunk_sz, size);
	push_back_chunks(a, b);
}
