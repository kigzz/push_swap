/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:06:19 by bpouchep          #+#    #+#             */
/*   Updated: 2022/01/18 16:06:36 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	push(t_dlst **src, t_dlst **dst)
{
	t_dlst	*tmp;
	int		src_sz;

	tmp = ft_dlstfirst(*src);
	src_sz = ft_dlstsize(*src);
	if (!*src)
		return (1);
	if (src_sz < 1)
		return (1);
	if (*dst == NULL)
	{
		*src = (*src)->next;
		if ((*src) != NULL)
			(*src)->prev = NULL;
		tmp->next = NULL;
	}
	else
	{
		(*src) = (*src)->next;
		tmp->next = *dst;
		if ((*src) != NULL)
			(*src)->prev = NULL;
		(*dst)->prev = tmp;
	}
	*dst = tmp;
	return (0);
}

void	pa(t_dlst **a, t_dlst **b, int print)
{
	if (push(b, a))
		return ;
	if (print)
		write(1, "pa\n", 3);
}

void	pb(t_dlst **a, t_dlst **b, int print)
{
	if (push(a, b))
		return ;
	if (print)
		write(1, "pb\n", 3);
}
