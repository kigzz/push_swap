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

void	sort_3(t_dlst **dlst)
{
	int	arr[3];

	arr[0] = (*dlst)->data;
	arr[1] = (*dlst)->next->data;
	arr[2] = (*dlst)->next->next->data;
	for (int i = 0; i < 3; i++)
		printf("%d\n", arr[i]);
	if (arr[0] > arr[1] && arr[1] < arr[2] && arr[2] > arr[0])
		sa(dlst, 1);
	else if (arr[0] > arr[1] && arr[1] > arr[2] && arr[2] < arr[0])
	{
		sa(dlst, 1);
		rra(dlst, 1);
	}
	else if (arr[0] > arr[1] && arr[1] < arr[2] && arr[2] < arr[0])
		ra(dlst, 1);
	else if (arr[0] < arr[1] && arr[1] > arr[2] && arr[2] > arr[0])
	{
		sa(dlst, 1);
		ra(dlst, 1);
	}
	else if (arr[0] < arr[1] && arr[1] > arr[2] && arr[2] < arr[0])
		rra(dlst, 1);
}

//void sort_5(t_dlst **dlst)
//{
//
//}