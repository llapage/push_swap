/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap_push_s_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:36:04 by llapage           #+#    #+#             */
/*   Updated: 2023/06/14 10:37:23 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	op_sx_s(t_node *head)
{
	int	temp;

	if (head && head->next)
	{
		temp = head->n;
		head->n = head->next->n;
		head->next->n = temp;
	}
}

void	op_ss_s(t_node *a, t_node *b)
{
	op_sx_s(a);
	op_sx_s(b);
}

void	op_px_s(t_node **head_in, t_node **head_out)
{
	t_node	*tmp;

	if (!(*head_out))
		return ;
	if ((*head_out)->next == (*head_out))
		tmp = NULL;
	else
		tmp = (*head_out)->next;
	(*head_out)->next->prev = (*head_out)->prev;
	(*head_out)->prev->next = (*head_out)->next;
	if ((*head_in))
	{
		(*head_out)->prev = (*head_in)->prev;
		(*head_out)->next = (*head_in);
		(*head_in)->prev->next = *head_out;
		(*head_in)->prev = *head_out;
	}
	else
	{
		(*head_out)->next = (*head_out);
		(*head_out)->prev = (*head_out);
	}
	(*head_in) = (*head_out);
	(*head_out) = tmp;
}
