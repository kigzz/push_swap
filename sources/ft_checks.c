/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 22:46:01 by bpouchep          #+#    #+#             */
/*   Updated: 2022/01/14 22:46:03 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_duplicate(int *arr, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

//void	check_input(int argc, char *argv[])
//{
//	int	i;
//	int	*arr;
//
//	if (argc == 1)
//		exit (0);
//	i = 0;
//	arr = malloc(sizeof(int) * (argc - 1));
//	if (!arr)
//		exit (1);
//	while (++i < argc)
//	{
//		if (ft_isdigit(argv[i]) == 0)
//		{
//			free(arr);
////			error();
//			printf("Error digit\n");
//			exit (1);
//		}
//			arr[i - 1] = ft_atoi(argv[i]);
//	}
//	if (check_duplicate(arr, argc - 1) == 1)
//	{
//		free(arr);
////		error();
//		printf("Error duplicate\n");
//		exit (1);
//	}
//	for (i = 0; i < argc -1; i++)
//		printf("%d\n", arr[i]);
//	free(arr);
//}
//
