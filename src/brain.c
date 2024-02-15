/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 14:10:44 by llapage           #+#    #+#             */
/*   Updated: 2023/06/13 13:34:15 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	brain(char **argv)
{
	t_node	*a;
	t_node	*b;
	t_store	*store;

	a = init_list(argv);
	store = malloc(sizeof(t_store));
	b = NULL;
	if (store && a && check_sort(&a))
	{
		if (lst_size(&a) <= 5)
			small_stack(store, &a, &b);
		else
		{
			op_px(&b, &a, 'b');
			op_px(&b, &a, 'b');
			algo(store, &a, &b);
		}
	}
	free_list(&a);
	free_list(&b);
	free(store);
}
