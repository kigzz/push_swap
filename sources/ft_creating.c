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

t_dlst	*create_list(int n_cnt, int *arr)
{
	t_dlst	*dlst;
	int		i;
	int		j;
	int		tmp;
	int		cnt;

	i = -1;
	dlst = NULL;
	while (++i < n_cnt)
	{
		{
			cnt = 0;
			j = -1;
			while (++j < n_cnt)
				if (j != i && arr[j] < arr[i])
					cnt++;
			tmp = cnt;
			ft_dlstadd_back(&dlst, ft_dlstnew(tmp));
		}
	}
	return (dlst);
}

int	*create_array(char **nbrs, int n_cnt)
{
	int	*arr;
	int	i;
	int	flag_min_max;

	i = -1;
	flag_min_max = 0;
	if (nbrs == NULL)
		return (NULL);
	arr = malloc(sizeof(int) * n_cnt);
	if (!arr)
		return (NULL);
	while (++i < n_cnt)
	{
		arr[i] = ft_atoi(nbrs[i], &flag_min_max);
	}
	if (flag_min_max == 1)
	{
		free(arr);
		return (NULL);
	}
	return (arr);
}
