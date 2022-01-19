#include "../includes/push_swap.h"

int *create_array(char *const *nbrs, int n_cnt);

char **parse_args(int argc, char **argv);

int check_numbers(char **nbrs);

t_dlist *create_list(int n_cnt, const int *arr);

int main (int argc, char *argv[])
{

	// Parsing des arguments :

	int i;
	char **nbrs = parse_args(argc, argv);
	int n_cnt;

//		Nombre de nbrs

	i = -1;
	n_cnt = 0;
	while (nbrs[++i])
		n_cnt++;
	printf("Nombre de nombre : %d\n", n_cnt);

	//		Check chaque case du tableau de *char s'il est valide
	//		Check si chaque case du tableau est un int (compris entre 2147483647 et -2147483648)
	//		En faisant un tableau d'int

	int *arr = create_array(nbrs, n_cnt);
	if (arr == NULL)
		return (1);

	// CHECK

	if (check_duplicate(arr, n_cnt) == 1 || check_numbers(nbrs) == 1)
	{
		int p = -1;
		while (nbrs[++p])
			free(nbrs[p]);
		free(arr);
		free(nbrs);
		ft_putstr_fd("Error\n", 1);
		return (1);
	}

	//			Initialisation de la liste chainée


	t_dlist *a_stack = create_list(n_cnt, arr);

	//	printf("qwe\n");

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

	// push A dans B
		// 1 fois

	printf("first %d - last %d\n", ft_dlstfirst(a_stack)->data, ft_dlstlast(a_stack)->data);
	printf("Taille de Stack B : %d\n", ft_dlstsize(b_stack));


	// Rotate stack
	// Reverse rotate stack
	// Swap first 2 element stack

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
	// Print stack A
	curr = ft_dlstfirst(a_stack);
	while (curr != NULL)
	{
		printf("Stack A après swap NEXT : %d\n", curr->data);
		curr = curr->next;

	}

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

	t_dlist *aux;
//	printf("a_stack = %d\n", a_stack->data);

	if (a_stack == NULL)
	{
		printf("Empty stack A\n");
		return (1);
	}
	aux = a_stack;
	while (aux->next != NULL)
	{
		aux = aux->next;
		free(aux->prev);
	}
	free(aux);
	return (0);
}

t_dlist *create_list(int n_cnt, const int *arr)
{
	t_dlist *a_stack;

	a_stack = NULL;
	int	i;

	i = 0;
	printf("n_cnt = %d\n", n_cnt);
	while (i < n_cnt)
	{
		ft_dlstadd_back(&a_stack, ft_dlstnew(arr[i]));
		i++;
	}
	a_stack->size = ft_dlstsize(a_stack);
	return (a_stack);
}

int check_numbers(char **nbrs)
{
	int	i;
	int j;

	i = -1;
	while (nbrs[++i])
	{
		j = -1;
		if (nbrs[i][0] == '-' || nbrs[i][0] == '+')
			j++;
		while (nbrs[i][++j])
		{
			if (ft_isdigit(nbrs[i]) == 0)
				return (1);
		}
	}
	return (0);
}

char **parse_args(int argc, char **argv)
{
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
	return (nbrs);
}

int *create_array(char *const *nbrs, int n_cnt)
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

//int main (int argc, char *argv[])
//{
//	check_input(argc, argv);
//	return (0);
//}

