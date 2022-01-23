/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 21:53:57 by bpouchep          #+#    #+#             */
/*   Updated: 2022/01/23 21:54:15 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	*ft_strcpy(char *dst, const char *src)
{
	char	*save;

	save = dst;
	while (*src)
		*dst++ = *src++;
	*dst = '\0';
	return (save);
}
