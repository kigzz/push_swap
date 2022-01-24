/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 22:12:08 by bpouchep          #+#    #+#             */
/*   Updated: 2022/01/24 22:12:19 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	is_space(char c)
{
	if ((c == '\t' || c == '\n' || c == '\v'
			|| c == '\f' || c == '\r' || c == ' '
			|| c == '\0'))
		return (0);
	else
		return (1);
}

int	is_empty(char *str)
{
	if (!str)
		return (1);
	while (*str)
	{
		if (is_space(*str) == 0)
			str++;
		else
			return (1);
	}
	return (0);
}

int	check_numbers_is_int(char *str)
{
	int	len;

	if (!str)
		return (1);
	len = ft_strlen(str);
	if (*str == '-' || *str == '+')
		len--;
	while (*str && *str == '0')
	{
		len--;
		str++;
	}
	while (*str)
	{
		if (!is_space(*str))
			len--;
		str++;
	}
	if (len > 10)
		return (1);
	else
		return (0);
}
