/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 19:19:41 by llapage           #+#    #+#             */
/*   Updated: 2023/06/10 18:54:55 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	min_max(t_node *head, t_store *store, int start)
{
	if (start == 0)
	{
		if (head->n < store->min)
		store->min = head->n;
		else if (head->n > store->max)
		store->max = head->n;
	}
	else
	{
		store->min = head->n;
		store->max = head->n;
		if (head->next->n < store->min)
			store->min = head->next->n;
		else if (head->next->n > store->max)
			store->max = head->next->n;
	}
}

void	solved(t_store *store, t_node **a, t_node **b)
{
	int	i;

	i = 0;
	if (lst_size(b) / 2 < store->cur_dist_b)
		store->cur_dist_b = store->cur_dist_b - lst_size(b);
	if (lst_size(a) / 2 < store->cur_dist_a)
		store->cur_dist_a = store->cur_dist_a - lst_size(a);
	if (store->cur_dist_b == 0)
		i = ft_abs(store->cur_dist_a);
	else if (store->cur_dist_a == 0)
		i = ft_abs(store->cur_dist_b);
	else if ((store->cur_dist_b < 0 && store->cur_dist_a > 0)
		|| (store->cur_dist_b > 0 && store->cur_dist_a < 0))
		i = ft_abs(store->cur_dist_b) + ft_abs(store->cur_dist_a);
	else if (store->cur_dist_b < 0 && store->cur_dist_a < 0)
		while (i < ft_abs(store->cur_dist_b) || i < ft_abs(store->cur_dist_a))
			i++;
	else if (store->cur_dist_b > 0 && store->cur_dist_a > 0)
		while (i < store->cur_dist_b || i < store->cur_dist_a)
			i++;
	if (i + 1 < store->cheaper_sol)
		save_sol(store, i);
	store->cur_dist_a++;
}

static void	rotate_a_b(t_store *store, t_node **a, t_node **b)
{
	reverse_rotate(store, a, b);
	while (store->distance_a < 0)
	{
		op_rrx(a, 'a');
		store->distance_a++;
	}
	while (store->distance_a > 0)
	{
		op_rx(a, 'a');
		store->distance_a--;
	}
	while (store->distance_b < 0)
	{
		op_rrx(b, 'b');
		store->distance_b++;
	}
	while (store->distance_b > 0)
	{
		op_rx(b, 'b');
		store->distance_b--;
	}
}

static void	push_b_to_a(t_store *store, t_node **a, t_node **b)
{
	t_node	*cur_b;
	int		j;

	cur_b = *b;
	j = 0;
	while (cur_b->n != store->max)
	{
		cur_b = cur_b->next;
		j++;
	}
	if (j < lst_size(b) / 2)
	{
		while ((*b)->n != store->max)
			op_rx(b, 'b');
	}
	else
	{
		while ((*b)->n != store->max)
			op_rrx(b, 'b');
	}
	while (*b)
		op_px(a, b, 'a');
}

void	algo(t_store *store, t_node **a, t_node **b)
{
	min_max(*b, store, 1);
	while (*a)
	{
		init_store(store, 0);
		check_solution(store, a, b);
		init_store(store, 1);
		check_rev_solution(store, a, b);
		rotate_a_b(store, a, b);
		op_px(b, a, 'b');
		min_max(*b, store, 0);
	}
	push_b_to_a(store, a, b);
}
