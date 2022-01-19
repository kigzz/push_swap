/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 20:12:23 by bpouchep          #+#    #+#             */
/*   Updated: 2022/01/19 20:12:35 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_split(char **nbrs)
{
	int	i;

	i = -1;
	while (nbrs[++i])
		free(nbrs[i]);
	free(nbrs);
}

void	free_tab(t_dlist **dlst)
{
	t_dlist	*tmp;

	if (*dlst == NULL)
		return ;
	tmp = *dlst;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		free(tmp->prev);
	}
	free(tmp);
}
