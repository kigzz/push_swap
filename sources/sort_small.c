/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 22:19:16 by bpouchep          #+#    #+#             */
/*   Updated: 2022/01/19 22:19:28 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_3(t_dlst **dlst)
{
	int	arr[3];

	arr[0] = (*dlst)->data;
	arr[1] = (*dlst)->next->data;
	arr[2] = (*dlst)->next->next->data;
	if (arr[0] > arr[1] && arr[1] < arr[2] && arr[2] > arr[0])
		sa(*dlst, 1);
	else if (arr[0] > arr[1] && arr[1] > arr[2] && arr[2] < arr[0])
	{
		sa(*dlst, 1);
		rra(dlst, 1);
	}
	else if (arr[0] > arr[1] && arr[1] < arr[2] && arr[2] < arr[0])
		ra(dlst, 1);
	else if (arr[0] < arr[1] && arr[1] > arr[2] && arr[2] > arr[0])
	{
		sa(*dlst, 1);
		ra(dlst, 1);
	}
	else if (arr[0] < arr[1] && arr[1] > arr[2] && arr[2] < arr[0])
		rra(dlst, 1);
}

static void	sort_5(t_dlst **a, t_dlst **b, int n_cnt)
{
	if (n_cnt == 5)
		pb(a, b, 1);
	pb(a, b, 1);
	sort_3(a);
	if (n_cnt == 5)
		smart_push(a, b);
	smart_push(a, b);
	sort_a(a);
}

void	sort_small(t_dlst **a, t_dlst **b, int n_cnt)
{
	if (ft_dlstsize(*a) == 2)
	{
		if ((*a)->data > (*a)->next->data)
			sa(*a, 1);
	}
	else if (ft_dlstsize(*a) == 3)
		sort_3(a);
	else
		sort_5(a, b, n_cnt);
}
