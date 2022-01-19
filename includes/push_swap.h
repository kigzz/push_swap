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
	int				data;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}	t_dlist;

/* libft function */

void	*ft_memcpy(void *dest, const void *src, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *src);
size_t	ft_strlen(const char *str);
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

/* free functions */

void	free_split(char **nbrs);
void	free_tab(t_dlist **dlst);

/* push_swap functions */

int		check_input(int argc, char **argv, int **arr);
char	**parse_args(int argc, char **argv);
int		*create_array(char **nbrs, int n_cnt);
t_dlist	*create_list(int n_cnt, int *arr);

/* ops */

void	pb(t_dlist **a, t_dlist **b, int print);
void	pa(t_dlist **a, t_dlist **b, int print);
void	sa(t_dlist *a, int print);
void	sb(t_dlist *a, int print);
void	ra(t_dlist **dlst, int print);
void	rb(t_dlist **dlst, int print);
void	rra(t_dlist **dlst, int print);
void	rrb(t_dlist **dlst, int print);
void	rr(t_dlist **a, t_dlist **b, int print);
void	rrr(t_dlist **a, t_dlist **b, int print);

#endif
