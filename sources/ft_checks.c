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

static int	check_duplicate(int *arr, int n)
{
	int	i;
	int	j;

	if (arr == NULL)
		return (1);
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

static int	check_numbers(char **nbrs)
{
	int	i;
	int	j;

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

char	**parse_args(int argc, char **argv)
{
	char	**nbrs;
	int		i;
	char	*av_str;
	char	*tmp;

	i = 0;
	av_str = ft_strdup("");
	while (++i < argc)
	{
		tmp = ft_strjoin(av_str, argv[i]);
		free(av_str);
		av_str = tmp;
		tmp = ft_strjoin(av_str, " ");
		free(av_str);
		av_str = tmp;
	}
	nbrs = ft_split(av_str, ' ');
	free(av_str);
	return (nbrs);
}

int	check_input(int argc, char **argv, int **array)
{
	char	**nbrs;
	int		n_cnt;
	int		i;

	nbrs = parse_args(argc, argv);
	i = -1;
	n_cnt = 0;
	while (nbrs[++i])
		n_cnt++;
	*array = create_array(nbrs, n_cnt);
	if (check_duplicate(*array, n_cnt) != 0 || check_numbers(nbrs) != 0
		|| array == NULL)
	{
		n_cnt = -1;
		free(*array);
		free_split(nbrs);
		ft_putstr_fd("Error\n", 1);
		return (n_cnt);
	}
	free_split(nbrs);
	return (n_cnt);
}
