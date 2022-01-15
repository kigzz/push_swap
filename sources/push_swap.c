#include "../includes/push_swap.h"

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
	for (i = 0; i < argc - 1; i++)
	{
		printf("%s ", nbrs[i]);
	}

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

	int *arr = malloc(sizeof(int) * n_cnt);
	if (!arr)
		return (1);
	i = -1;
	while (++i < n_cnt)
	{
		arr[i] = ft_atoi(nbrs[i]);
	}
	for (i = 0; i < n_cnt; i++)
		printf("arr %d\n", arr[i]);

	//		Check s'il y a des doublons en faisant

	if (ft_duplicate(arr, n_cnt))
	{
		free(arr);
		printf("Error duplicate\n");
		return (2);
	}
	i = -1;
	while (nbrs[++i])
		free(nbrs[i]);
	free(nbrs);
//	free(arr);

	//			Initialisation de la liste chainée




	return (0);
}

//int main (int argc, char *argv[])
//{
//	check_input(argc, argv);
//	return (0);
//}

