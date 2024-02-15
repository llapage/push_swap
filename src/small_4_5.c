/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_4_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:49:14 by llapage           #+#    #+#             */
/*   Updated: 2023/06/10 17:59:46 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotate(t_store *store, t_node **a, int size)
{
	t_node	*cur_a;

	cur_a = *a;
	if (cur_a->next->n == store->max
		|| (size == 5 && cur_a->next->next->n == store->max))
	{
		while (cur_a->n != store->max)
		{
			op_rx(a, 'a');
			cur_a = cur_a->next;
		}
	}
	else
	{
		while (cur_a->n != store->max)
		{
			op_rrx(a, 'a');
			cur_a = cur_a->prev;
		}
	}
}

void	size_4_5(t_store *store, t_node **a, t_node **b)
{
	int		size;

	size = lst_size(a);
	min_max_small(*a, store);
	rotate(store, a, size);
	op_px(b, a, 'b');
	if (size == 5)
	{
		min_max_small(*a, store);
		rotate(store, a, size);
		op_px(b, a, 'b');
		size_3(a, store);
		size_2(b, 'b');
		op_px(a, b, 'a');
		op_rx(a, 'a');
		op_px(a, b, 'a');
		op_rx(a, 'a');
	}
	else
	{
		size_3(a, store);
		op_px(a, b, 'a');
		op_rx(a, 'a');
	}
}
