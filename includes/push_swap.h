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

typedef struct s_dlst
{
	int				data;
	struct s_dlst	*next;
	struct s_dlst	*prev;
}	t_dlst;

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

void	ft_dlstadd_back(t_dlst **dlst, t_dlst *new);
void	ft_dlstadd_front(t_dlst **dlst, t_dlst *new);
t_dlst	*ft_dlstfirst(t_dlst *dlst);
t_dlst	*ft_dlstlast(t_dlst *dlst);
t_dlst	*ft_dlstnew(int data);
int		ft_dlstsize(t_dlst *dlst);

/* free functions */

void	free_split(char **nbrs);
void	free_tab(t_dlst **dlst);

/* push_swap functions */

int		check_input(int argc, char **argv, int **arr);
char	**parse_args(int argc, char **argv);
int		*create_array(char **nbrs, int n_cnt);
t_dlst	*create_list(int n_cnt, int *arr);

/* ops */

void	pb(t_dlst **a, t_dlst **b, int print);
void	pa(t_dlst **a, t_dlst **b, int print);
void	sa(t_dlst **a, int print);
void	sb(t_dlst **a, int print);
void	ra(t_dlst **dlst, int print);
void	rb(t_dlst **dlst, int print);
void	rra(t_dlst **dlst, int print);
void	rrb(t_dlst **dlst, int print);
void	rr(t_dlst **a, t_dlst **b, int print);
void	rrr(t_dlst **a, t_dlst **b, int print);

/* sort */

void	sort_3(t_dlst **dlst);

#endif
