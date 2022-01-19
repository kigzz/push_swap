/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabs_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:38:11 by bpouchep          #+#    #+#             */
/*   Updated: 2022/01/19 17:38:25 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_dlist *create_list(int n_cnt, int *arr)
{
	t_dlist *a_stack;

	a_stack = NULL;
	int	i;

	i = 0;
	while (i < n_cnt)
	{
		ft_dlstadd_back(&a_stack, ft_dlstnew(arr[i]));
		i++;
	}
	return (a_stack);
}

int *create_array(char **nbrs, int n_cnt)
{
	int *arr;
	int i;

	i = -1;
	arr = malloc(sizeof(int) * n_cnt);
	if (!arr)
		return NULL;
	while (++i < n_cnt)
		arr[i] = ft_atoi(nbrs[i]);
	return (arr);
}

