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

	if (argc == 1)
		return (0);
	n_cnt = check_input(argc, argv, &arr);
	if (n_cnt < 0 || arr == NULL)
		return (1);

	//			Initialisation de la liste chainée

	a_stack = create_list(n_cnt, arr);

				// TEST TEST

	t_dlst *curr = a_stack;
	while (curr != NULL)
	{
		printf("Init Stack A : %d\n", curr->data);
		curr = curr->next;

	}
	printf("Taille de Stack A : %d\n", ft_dlstsize(a_stack));

//		TEST OPS


	t_dlst *b_stack;
	b_stack = NULL;

	printf("first %d - last %d\n", ft_dlstfirst(a_stack)->data, ft_dlstlast(a_stack)->data);

	//	sa(a_stack, 0);
//	pb(&a_stack, &b_stack, 0);
//	sa(a_stack, 0);
//	pb(&a_stack, &b_stack, 0);
//	sb(b_stack, 0);
//	sb(b_stack, 0);
//	pa(&a_stack, &b_stack, 0);
//	pb(&a_stack, &b_stack, 0);
//	pb(&a_stack, &b_stack, 0);
//	pb(&a_stack, &b_stack, 0);
////	pa(&a_stack, &b_stack, 0);
//
//	sb(b_stack, 0);
//	rrr(&a_stack, &b_stack, 0);
//

	// Print stack A

	sort_3(&a_stack);

	curr = a_stack;
	while (curr != NULL)
	{
		printf("A après OPS : %d\n", curr->data);
		curr = curr->next;
	}
	curr = b_stack;
//	while (curr)
//	{
//		printf("- B après OPS : %d\n", curr->data);
//		curr = curr->next;
//	}
	//		Leaks

	free(arr);
	free_tab(&a_stack);
	free_tab(&b_stack);
	return (0);
}
