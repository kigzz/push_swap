/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 20:25:04 by bpouchep          #+#    #+#             */
/*   Updated: 2020/07/15 20:25:18 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*out;

	if (!s1 || !s2)
		return (NULL);
	out = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!out)
		return (NULL);
	ft_strcpy(out, s1);
	ft_strcat(out, s2);
	return (out);
}
