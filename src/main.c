/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:58:21 by llapage           #+#    #+#             */
/*   Updated: 2023/06/12 15:17:01 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	argv = clean_argv(argc, argv);
	if (!argv)
		return (0);
	if (verify_argv(argv) == -1)
	{
		ft_printf("Error\n");
		if (argc == 2)
			free_argv(argv);
		return (0);
	}
	brain(argv);
	if (argc == 2)
		free_argv(argv);
	return (0);
}
