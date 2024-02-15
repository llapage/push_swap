/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate_s_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:05:32 by llapage           #+#    #+#             */
/*   Updated: 2023/06/14 10:30:31 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	op_rx_s(t_node **head)
{
	if (*head)
		(*head) = (*head)->next;
}

void	op_rr_s(t_node **a, t_node **b)
{
	op_rx_s(a);
	op_rx_s(b);
}

void	op_rrx_s(t_node **head)
{
	if (*head)
		(*head) = (*head)->prev;
}

void	op_rrr_s(t_node **a, t_node **b)
{
	op_rrx_s(a);
	op_rrx_s(b);
}
