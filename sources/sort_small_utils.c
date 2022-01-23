/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 02:33:30 by bpouchep          #+#    #+#             */
/*   Updated: 2022/01/20 02:33:42 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	is_min_or_max(t_dlst *a, t_dlst *element, int find_min)
{
	if (find_min == 1)
	{
		while (a)
		{
			if (a->data < element->data)
				return (0);
			a = a->next;
		}
	}
	else
	{
		while (a)
		{
			if (a->data > element->data)
				return (0);
			a = a->next;
		}
	}
	return (1);
}

static void	smart_rotate_a(t_dlst **a, int move_cnt)
{
	int	a_size;

	a_size = ft_dlstsize(*a);
	if (move_cnt > a_size / 2)
	{
		move_cnt = a_size - move_cnt;
		while (move_cnt--)
			rra(a, 1);
	}
	else
		while (move_cnt--)
			ra(a, 1);
}

static int	get_ins_pos(t_dlst *a, int data)
{
	int	pos;
	int	prev_data;

	pos = 0;
	prev_data = ft_dlstlast(a)->data;
	while (a && !(data < a->data && data > prev_data))
	{
		pos++;
		a = a->next;
		prev_data = a->prev->data;
	}
	return (pos);
}

void	smart_push(t_dlst **a, t_dlst **b)
{
	if (is_min_or_max(*a, *b, 1))
	{
		sort_a(a);
		pa(a, b, 1);
	}
	else if (is_min_or_max(*a, *b, 0))
	{
		sort_a(a);
		pa(a, b, 1);
		ra(a, 1);
	}
	else
	{
		smart_rotate_a(a, get_ins_pos(*a, (*b)->data));
		pa(a, b, 1);
	}
}

void	sort_a(t_dlst **a)
{
	int		move_cnt;
	t_dlst	*tmp;

	move_cnt = 0;
	tmp = *a;
	while (tmp)
	{
		if (is_min_or_max(*a, tmp, 1))
			break ;
		move_cnt++;
		tmp = tmp->next;
	}
	smart_rotate_a(a, move_cnt);
}
