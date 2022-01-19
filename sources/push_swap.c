#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{

	// Parsing des arguments :

	int		n_cnt;
	t_dlist	*a_stack;
	int		*arr;


//		Nombre de nbrs

	n_cnt = check_input(argc, argv, &arr);
	if (n_cnt < 0 || arr == NULL)
	{
		free(arr);
		return (1);
	}

	// CHECK

	//			Initialisation de la liste chainée

	a_stack = create_list(n_cnt, arr);
	free(arr);

				// TEST TEST

	t_dlist *curr = a_stack;
	while (curr != NULL)
	{
		printf("Init Stack A : %d\n", curr->data);
		curr = curr->next;

	}
	printf("Taille de Stack A : %d\n", ft_dlstsize(a_stack));

//		TEST OPS


	t_dlist *b_stack;
	b_stack = NULL;

	printf("first %d - last %d\n", ft_dlstfirst(a_stack)->data, ft_dlstlast(a_stack)->data);

	//	sa(a_stack, 0);
//	pb(&a_stack, &b_stack, 0);
//	sa(a_stack, 0);
//	pb(&a_stack, &b_stack, 0);
//	sb(b_stack, 0);
//	sb(b_stack, 0);
//	pa(&a_stack, &b_stack, 0);
	pb(&a_stack, &b_stack, 0);
	pb(&a_stack, &b_stack, 0);
	pb(&a_stack, &b_stack, 0);
	rrr(&a_stack, &b_stack, 0);
	pa(&a_stack, &b_stack, 0);
	pa(&a_stack, &b_stack, 0);
	pa(&a_stack, &b_stack, 0);
	// Print stack A
	curr = ft_dlstfirst(a_stack);
	while (curr != NULL)
	{
		printf("Stack A après OPS : %d\n", curr->data);
		curr = curr->next;

	}

	curr = b_stack;
	while (curr)
	{
		printf("Stack B après OPS : %d\n", curr->data);
		curr = curr->next;
	}
	//		Leaks

	free_tab(&a_stack);
	return (0);
}
