/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 21:06:26 by bpouchep          #+#    #+#             */
/*   Updated: 2022/01/19 21:06:28 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	int		n_cnt;
	int		*arr;
	t_dlst	*a_stack;
	t_dlst	*b_stack;

	b_stack = NULL;
	if (argc == 1)
		return (0);
	n_cnt = check_input(argc, argv, &arr);
	if (n_cnt < 0 || arr == NULL)
		return (1);
	a_stack = create_list(n_cnt, arr);
	free(arr);
	handle_sort(&a_stack, &b_stack, n_cnt);
	free_tab(&a_stack);
	free_tab(&b_stack);
	return (0);
}
