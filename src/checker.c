/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:33:09 by llapage           #+#    #+#             */
/*   Updated: 2023/06/12 13:40:15 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	checker(t_node *a)
{
	char	**op;
	int		i;

	i = 0;
	while (i == 0 || op[i] != NULL)
	{
		op[i] = get_next_line(0);
		i++;
	}
}
