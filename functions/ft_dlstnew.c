/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:34:51 by bpouchep          #+#    #+#             */
/*   Updated: 2022/01/15 15:34:53 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_dlist	*ft_dlstnew(int data)
{
	t_dlist	*newdlst;

	newdlst = (t_dlist *)malloc(sizeof(t_dlist));
	if (!newdlst)
		return (NULL);
	newdlst->data = data;
	newdlst->next = NULL;
	newdlst->prev = NULL;
	return (newdlst);
}
