/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:33:10 by llapage           #+#    #+#             */
/*   Updated: 2023/06/10 18:55:33 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reverse_rotate(t_store *store, t_node **a, t_node **b)
{
	while (store->distance_a < 0 && store->distance_b < 0)
	{
		op_rrr(a, b);
		store->distance_a++;
		store->distance_b++;
	}
	while (store->distance_a > 0 && store->distance_b > 0)
	{
		op_rr(a, b);
		store->distance_a--;
		store->distance_b--;
	}
}
