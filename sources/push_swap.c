#include "../includes/push_swap.h"

int *create_array(char *const *nbrs, int n_cnt);

int main (int argc, char *argv[])
{

	// Parsing des arguments :

	// 		Faire en sorte que les arguments recus soient une de la forme **char avec ft_split.c

	char **nbrs;
	int i = 0;
	char *av_str;
	av_str = ft_strdup("");
	while (++i < argc)
	{
		char *tmp;
		tmp = ft_strjoin(av_str, argv[i]);
		free(av_str);
		av_str = tmp;
		tmp = ft_strjoin(av_str, " ");
		free(av_str);
		av_str = tmp;
	}
//	printf("av_str = %s\n", av_str);

	nbrs = ft_split(av_str, ' ');
	free(av_str);
//	printf("argc = %d\n", argc);
//	for (i = 0; i < argc - 1; i++)
//	{
//		printf("%s ", nbrs[i]);
//	}

//		Nombre de nbrs

	i = -1;
	int n_cnt = 0;
	while (nbrs[++i])
	{
		n_cnt++;
	}
	printf("Nombre de nombre : %d\n", n_cnt);

	//		Check chaque case du tableau de *char s'il est valide

	i = -1;
	int j;
	while (nbrs[++i])
	{
		j = -1;
		if (nbrs[i][0] == '-' || nbrs[i][0] == '+')
			j++;
		while (nbrs[i][++j])
		{
			if (ft_isdigit(nbrs[i]) == 0)
			{
				int p = -1;
				while (nbrs[++p])
					free(nbrs[p]);
				free(nbrs);
				printf("Error digit\n");
				return (1);
			}
		}
	}

	//		Check si chaque case du tableau est un int (compris entre 2147483647 et -2147483648)
	//		En faisant un tableau d'int

	int *arr = create_array(nbrs, n_cnt);
	if (arr == NULL)
		return (1);
//	for (i = 0; i < n_cnt; i++)
//		printf("arr %d\n", arr[i]);

	//		Check s'il y a des doublons en faisant

	if (ft_duplicate(arr, n_cnt))
	{
		int p = -1;
		while (nbrs[++p])
			free(nbrs[p]);
		free(nbrs);
		free(arr);
		printf("Error duplicate\n");
		return (2);
	}


	//			Initialisation de la liste chainée


	t_dlist *a_stack;

	a_stack = NULL;

	for (i = 0; i < n_cnt; i++)
		printf("arr %d\n", arr[i]);
	i = 0;
	printf("n_cnt = %d\n", n_cnt);
	while (i < n_cnt)
	{
		ft_dlstadd_back(&a_stack, ft_dlstnew(arr[i]));
		i++;
	}
//	printf("qwe\n");

	t_dlist *curr = a_stack;
	while (curr != NULL)
	{
		printf("Init Stack A : %d\n", curr->data);
		curr = curr->next;

	}
	printf("Taille de Stack A : %d\n", ft_dlstsize(a_stack));
	t_dlist *b_stack;

	b_stack = NULL;

	// push A dans B
		// 1 fois


	printf("first %d - last %d\n", ft_dlstfirst(a_stack)->data, ft_dlstlast(a_stack)->data);

	b_stack = ft_dlstfirst(a_stack);
	a_stack = a_stack->next;
	a_stack->prev = NULL;
	b_stack->next = NULL;

	// 2 fois

	t_dlist *tmp = ft_dlstfirst(a_stack);
	a_stack = a_stack->next;
	a_stack->prev = NULL;
	tmp->next = b_stack;
	b_stack->prev = tmp;
	b_stack = tmp;

	// 3 fois

	tmp = ft_dlstfirst(a_stack);
	a_stack = a_stack->next;
	a_stack->prev = NULL;
	tmp->next = b_stack;
	b_stack->prev = tmp;
	b_stack = tmp;

	// 4e et last fois

	tmp = ft_dlstfirst(a_stack);
	a_stack = NULL;
	tmp->next = b_stack;
	b_stack->prev = tmp;
	b_stack = tmp;

	a_stack = ft_dlstfirst(b_stack);
	b_stack = b_stack->next;
	b_stack->prev = NULL;
	a_stack->next = NULL;

	tmp = ft_dlstfirst(b_stack);
	b_stack = b_stack->next;
	b_stack->prev = NULL;
	tmp->next = a_stack;
	a_stack->prev = tmp;




//	tmp = ft_dlstfirst(a_stack);
//	a_stack = NULL;					// IF DERNIER ELEMENT A PUSH. RENDRE NULL LA LISTE VIDE
//	tmp->next = b_stack;
//	b_stack->prev = tmp;
//	b_stack = tmp;




//	a_stack = a_stack->next;
//	a_stack->next->prev = NULL;



	// Rotate stack
	// Reverse rotate stack
	// Swap first 2 element stack


	// Print stack A
	curr = ft_dlstfirst(a_stack);
	while (curr != NULL)
	{
		printf("Stack A après swap NEXT : %d\n", curr->data);
		curr = curr->next;

	}
//	curr = ft_dlstlast(a_stack);
//	while (curr != NULL)
//	{
//		printf("Stack A après swap PREV : %d\n", curr->data);
//		curr = curr->prev;
//
//	}
	curr = b_stack;
	while (curr)
	{
		printf("Stack B : %d\n", curr->data);
		curr = curr->next;
	}

	//		Leaks
	free(arr);
	i = -1;
	while (nbrs[++i])
		free(nbrs[i]);
	free(nbrs);
//	t_dlist *aux;
//	while (aux->next != NULL)
//	{
//		aux = a_stack;
//		a_stack = a_stack->next;
//		free(aux);
//	}
	return (0);
}

int *create_array(char *const *nbrs, int n_cnt) {
	int *arr = malloc(sizeof(int) * n_cnt);
	if (!arr)
		return NULL;

	int i = -1;
	while (++i < n_cnt)
	{
		arr[i] = ft_atoi(nbrs[i]);
	}
	return arr;
}

//int main (int argc, char *argv[])
//{
//	check_input(argc, argv);
//	return (0);
//}

