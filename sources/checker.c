/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 04:06:34 by bpouchep          #+#    #+#             */
/*   Updated: 2022/01/25 04:06:45 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	err_kill(t_dlst **a, t_dlst **b)
{
	ft_putstr_fd("Error\n", 2);
	free_tab(a);
	free_tab(b);
	exit(1);
}

static int	is_sorted(t_dlst **a, t_dlst **b, int n_cnt)
{
	t_dlst	*tmp;

	if (ft_dlstsize(*b) || ft_dlstsize(*a) != n_cnt)
		return (0);
	tmp = *a;
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static void	command_line(t_dlst **a, t_dlst **b, char *line)
{
	if (!ft_strncmp(line, "sa\n", 3))
		sa(a, 0);
	else if (!ft_strncmp(line, "sb\n", 3))
		sb(b, 0);
	else if (!ft_strncmp(line, "ss\n", 3))
		ss(a, b, 0);
	else if (!ft_strncmp(line, "pa\n", 3))
		pa(a, b, 0);
	else if (!ft_strncmp(line, "pb\n", 3))
		pb(a, b, 0);
	else if (!ft_strncmp(line, "ra\n", 3))
		ra(a, 0);
	else if (!ft_strncmp(line, "rb\n", 3))
		rb(b, 0);
	else if (!ft_strncmp(line, "rr\n", 3))
		rr(a, b, 0);
	else if (!ft_strncmp(line, "rra\n", 4))
		rra(a, 0);
	else if (!ft_strncmp(line, "rrb\n", 4))
		rrb(b, 0);
	else if (!ft_strncmp(line, "rrr\n", 4))
		rrr(a, b, 0);
	else
		err_kill(a, b);
}

static void	handle_check(t_dlst **a, t_dlst **b, int n_cnt)
{
	char	*line;

	line = ft_get_next_line(0);
	while (line)
	{
		command_line(a, b, line);
		free(line);
		line = ft_get_next_line(0);
	}
	free(line);
	if (is_sorted(a, b, n_cnt))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

int	main(int argc, char **argv)
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
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	a_stack = create_list(n_cnt, arr);
	free(arr);
	handle_check(&a_stack, &b_stack, n_cnt);
	free_tab(&a_stack);
	free_tab(&b_stack);
	return (0);
}
