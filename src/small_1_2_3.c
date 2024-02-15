/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_1_2_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 10:47:35 by llapage           #+#    #+#             */
/*   Updated: 2023/06/12 11:13:53 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	min_max_small(t_node *head, t_store *store)
{
	t_node	*cur_a;

	cur_a = head;
	store->min = cur_a->n;
	store->max = cur_a->n;
	cur_a = cur_a->next;
	while (cur_a != head)
	{
		if (cur_a->n < store->min)
			store->min = cur_a->n;
		if (cur_a->n > store->max)
			store->max = cur_a->n;
		cur_a = cur_a->next;
	}
}

void	size_3(t_node **head, t_store *store)
{
	min_max_small(*head, store);
	if ((*head)->n == store->max)
		op_rx(head, 'a');
	else if ((*head)->next->n == store->max)
		op_rrx(head, 'a');
	if ((*head)->n > ((*head)->next->n))
		op_sx(*head, 'a');
}

void	size_2(t_node **head, char c)
{
	if ((*head)->n > ((*head)->next->n))
		op_sx(*head, c);
}

void	small_stack(t_store *store, t_node **a, t_node **b)
{
	if (lst_size(a) <= 1)
		return ;
	else if (lst_size(a) <= 2)
		size_2(a, 'a');
	else if (lst_size(a) == 3)
		size_3(a, store);
	else if (lst_size(a) >= 4)
		size_4_5(store, a, b);
}
