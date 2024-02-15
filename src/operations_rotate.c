/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:15:06 by llapage           #+#    #+#             */
/*   Updated: 2023/06/14 10:42:32 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	op_rx(t_node **head, char c)
{
	if (*head)
	{
		(*head) = (*head)->next;
		if (c == 'b')
			ft_printf("rb\n");
		else if (c == 'a')
			ft_printf("ra\n");
	}
}

void	op_rr(t_node **a, t_node **b)
{
	op_rx(a, 'c');
	op_rx(b, 'c');
	ft_printf("rr\n");
}

void	op_rrx(t_node **head, char c)
{
	if (*head)
	{
		(*head) = (*head)->prev;
		if (c == 'a')
			ft_printf("rra\n");
		else if (c == 'b')
			ft_printf("rrb\n");
	}
}

void	op_rrr(t_node **a, t_node **b)
{
	op_rrx(a, 'c');
	op_rrx(b, 'c');
	ft_printf("rrr\n");
}
