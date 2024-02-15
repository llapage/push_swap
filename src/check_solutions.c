/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_solutions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:40:08 by llapage           #+#    #+#             */
/*   Updated: 2023/06/10 16:35:52 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_solution(t_store *store, t_node **a, t_node **b)
{
	t_node	*cur_a;
	t_node	*cur_b;

	cur_a = *a;
	cur_b = *b;
	while (cur_a != *a || store->found_sol == 0)
	{
		if ((cur_b->n == store->max && store->max < cur_a->n)
			|| (cur_b->n == store->max && store->min > cur_a->n)
			|| (cur_a->n > cur_b->n && cur_a->n < cur_b->prev->n))
		{
			store->found_sol = 1;
			solved(store, a, b);
			cur_a = cur_a->next;
			cur_b = *b;
			store->cur_dist_b = 0;
		}
		else
		{
			cur_b = cur_b->next;
			store->cur_dist_b++;
		}
	}
}

void	check_rev_solution(t_store *store, t_node **a, t_node **b)
{
	t_node	*cur_a;
	t_node	*cur_b;

	cur_a = *a;
	cur_b = *b;
	while (cur_a != *a || store->found_sol == 0)
	{
		if ((cur_b->n == store->max && store->max < cur_a->n)
			|| (cur_b->n == store->max && store->min > cur_a->n)
			|| (cur_a->n > cur_b->n && cur_a->n < cur_b->prev->n))
		{
			store->found_sol = 1;
			solved(store, a, b);
			cur_a = cur_a->next;
			cur_b = (*b);
			store->cur_dist_b = 0;
		}
		else
		{
			cur_b = cur_b->prev;
			store->cur_dist_b--;
		}
	}
}
