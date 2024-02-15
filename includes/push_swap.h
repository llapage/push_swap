/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:24:25 by llapage           #+#    #+#             */
/*   Updated: 2023/06/13 15:58:00 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../dep/ft_printf/includes/ft_printf.h"
# include "../dep/libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_node
{
	int				n;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_store
{
	int		cheaper_sol;
	int		max;
	int		min;
	int		cur_dist_a;
	int		cur_dist_b;
	int		distance_a;
	int		distance_b;
	int		found_sol;
}	t_store;

void			brain(char **argv);
t_node			*init_list(char **argv);
char			**clean_argv(int argc, char **argv);
void			op_sx(t_node *head, char c);
void			op_ss(t_node *a, t_node *b);
void			op_px(t_node **head_in, t_node **head_out, char c);
void			op_rx(t_node **head, char c);
void			op_rr(t_node **head1, t_node **head2);
void			op_rrx(t_node **head, char c);
void			op_rrr(t_node **head1, t_node **head2);
void			algo(t_store *store, t_node **a, t_node **b);
int				lst_size(t_node **head);
void			print(t_node **a, t_node **b);
int				ft_abs(int n);
void			small_stack(t_store *store, t_node **a, t_node **b);
void			free_list(t_node **head);
void			init_store(t_store *store, int rev);
void			check_solution(t_store *store, t_node **a, t_node **b);
void			check_rev_solution(t_store *store, t_node **a, t_node **b);
void			solved(t_store *store, t_node **a, t_node **b);
void			save_sol(t_store *store, int i);
void			size_2(t_node **head, char c);
void			size_3(t_node **head, t_store *store);
void			size_4_5(t_store *store, t_node **a, t_node **b);
void			min_max_small(t_node *head, t_store *store);
void			reverse_rotate(t_store *store, t_node **a, t_node **b);
int				verify_argv(char **argv);
void			free_argv(char **argv);
long long		ft_atoi_ps(const char *str);
int				check_sort(t_node **a);
char			*get_next_line(int fd);
char			*g_strjoin(char const *s1, char const *s2);
char			*g_strchr(const char *str, int c);
unsigned int	g_strlcpy(char *dest, const char *src, unsigned int size);
char			*ft_strdupchr(const char *src, char c);
void			*g_memset(void *b, int c, size_t len);
void			op_sx_s(t_node *head);
void			op_ss_s(t_node *a, t_node *b);
void			op_px_s(t_node **head_in, t_node **head_out);
void			op_rx_s(t_node **head);
void			op_rr_s(t_node **a, t_node **b);
void			op_rrx_s(t_node **head);
void			op_rrr_s(t_node **a, t_node **b);
int				check_sort_2(t_node **a);
long long		ft_atoi_ps_2(const char *str);
void			free_list_2(t_node **head);
void			free_argv_2(int argc, char **argv);
char			**clean_argv_2(int argc, char **argv);
int				verify_argv_2(char **argv);
int				check_tab_2(int *tab, int len);
t_node			*init_list_2(char **argv);
void			ft_free(t_node **a, t_node **b);

#endif
