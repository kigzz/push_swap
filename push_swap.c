#include "push_swap.h"
#include <limits.h>



int main (int argc, char *argv[])
{
	//			Pas d'arguments = return 0;

	if (argc == 1) {
		return (0);
	}
	// 2 arguments = Check qui est le plus grand et voir quelle move utiliser //

	// 						Check args

	int i = 0;
	int *arr = malloc(sizeof(int) * (argc- 1));
	while (++i < argc)
	{
		//			is digit + INT_MIN + INT_MAX
		if (ft_isdigit(argv[i]) == 0)
		{
			printf("Error digit\n");
			return (1);
		}
		else
		{
			arr[i - 1] = ft_atoi(argv[i]);
//			printf("arr %ld\n", arr[i - 1]);
		}
	}
	for (i = 0; i < argc - 1; i++)
	{
		printf("arr = %d\n", arr[i]);
	}
//	printf("duplicate %d\n", ft_duplicate(arr, argc -1));
//					Check des doublons

	if (ft_duplicate(arr, argc - 1) != 0)
	{
		printf("Error double\n");
		return (1);
	}
	free(arr);

	//
	return (0);
}