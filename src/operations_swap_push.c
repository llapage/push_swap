/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap_push.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 12:38:57 by llapage           #+#    #+#             */
/*   Updated: 2023/06/14 10:40:32 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	op_sx(t_node *head, char c)
{
	int	temp;

	if (head && head->next)
	{
		temp = head->n;
		head->n = head->next->n;
		head->next->n = temp;
		ft_printf("s%c\n", c);
	}
}

void	op_ss(t_node *a, t_node *b)
{
	op_sx(a, 'a');
	op_sx(b, 'b');
}

void	op_px(t_node **head_in, t_node **head_out, char c)
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
	ft_printf("p%c\n", c);
}
