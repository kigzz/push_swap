/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:55:48 by bpouchep          #+#    #+#             */
/*   Updated: 2022/01/13 14:55:51 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct Node
{
	int			x;
	struct Node	*next;
	struct Node *prev;
}	t_Node;

void	*ft_memcpy(void *dest, const void *src, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *src);
size_t	ft_strlen(const char *str);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
int	ft_atoi(const char *str);
int	ft_isdigit(const char *str);
void	ft_sort(int *arr, int n);
int ft_duplicate(int *arr, int n);

#endif
