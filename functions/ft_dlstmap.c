/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:34:39 by bpouchep          #+#    #+#             */
/*   Updated: 2022/01/15 15:34:41 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_dlist	*ft_dlstmap(t_dlist *dlst, void *(*f)(void *), void (*del)(void *))
{
	t_dlist *new;
	t_dlist *newdlst;

	if (!dlst || !f)
		return (NULL);
	newdlst = NULL;
	while (dlst)
	{
		new = ft_dlstnew(f(dlst->data));
		if (!new) {
			ft_dlstclear(&newdlst, del);
			return (NULL);
		}
		ft_dlstadd_back(&newdlst, new);
		dlst = dlst->next;
	}
	return (newdlst);
}
