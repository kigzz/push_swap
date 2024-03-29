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
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# ifndef MAX_OPEN
#  define MAX_OPEN 1024
# endif

typedef struct s_dlst
{
	int				data;
	struct s_dlst	*next;
	struct s_dlst	*prev;
}	t_dlst;

/* libft functions */

void	*ft_memcpy(void *dest, const void *src, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *src);
size_t	ft_strlen(const char *str);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_atoi(const char *str, int *flags);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_isdigit(char c);

/* Checker functions */

char	*ft_get_next_line(int fd);
char	*ft_strchr(const char *str, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

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
int		check_numbers_is_int(char *str);
int		is_empty(char *str);
int		*create_array(char **nbrs, int n_cnt);
t_dlst	*create_list(int n_cnt, int *arr);

/* ops */

void	pb(t_dlst **a, t_dlst **b, int print);
void	pa(t_dlst **a, t_dlst **b, int print);
void	sa(t_dlst **a, int print);
void	sb(t_dlst **a, int print);
void	ss(t_dlst **a, t_dlst **b, int print);
void	ra(t_dlst **dlst, int print);
void	rb(t_dlst **dlst, int print);
void	rra(t_dlst **dlst, int print);
void	rrb(t_dlst **dlst, int print);
void	rr(t_dlst **a, t_dlst **b, int print);
void	rrr(t_dlst **a, t_dlst **b, int print);

/* sort */

void	handle_sort(t_dlst **a, t_dlst **b, int n_cnt);
void	sort_a(t_dlst **a);
void	smart_push(t_dlst **a, t_dlst **b);
void	sort_small(t_dlst **a, t_dlst **b, int n_cnt);
int		smart_rotate_b(t_dlst **a, t_dlst **b);
void	sort_big(t_dlst **a, t_dlst **b, int size);

#endif
