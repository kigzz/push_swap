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

typedef struct s_dlist
{
	int 			data;
	struct s_dlist	*next;
	struct s_dlist	*prev;
	int 			size;
}	t_dlist;

/* libft function */

void	*ft_memcpy(void *dest, const void *src, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *src);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_atoi(const char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_isdigit(const char *str);

/* double link list functions */

void	ft_dlstadd_back(t_dlist **dlst, t_dlist *new);
void	ft_dlstadd_front(t_dlist **dlst, t_dlist *new);
t_dlist	*ft_dlstfirst(t_dlist *dlst);
t_dlist	*ft_dlstlast(t_dlist *dlst);
t_dlist	*ft_dlstnew(int data);
int		ft_dlstsize(t_dlist *dlst);

/* push_swap functions */

void	ft_sort(int *arr, int n);
int		check_duplicate(int *arr, int n);
void	check_input(int argc, char *argv[]);
void	error(void);

/* ops */

void pb(t_dlist **a, t_dlist **b, int print);
void pa(t_dlist **a, t_dlist **b, int print);


#endif
