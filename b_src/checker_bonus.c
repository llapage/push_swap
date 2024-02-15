/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:09:12 by llapage           #+#    #+#             */
/*   Updated: 2023/06/14 11:08:42 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_op(char *cmd, t_node **a, t_node **b)
{
	if (!ft_memcmp("sa\n", cmd, 3) || !ft_memcmp("sb\n", cmd, 3)
		|| !ft_memcmp("ss\n", cmd, 3) || !ft_memcmp("pa\n", cmd, 3)
		|| !ft_memcmp("pb\n", cmd, 3) || !ft_memcmp("ra\n", cmd, 3)
		|| !ft_memcmp("rb\n", cmd, 3) || !ft_memcmp("rr\n", cmd, 3)
		|| !ft_memcmp("rra\n", cmd, 4) || !ft_memcmp("rrb\n", cmd, 4)
		|| !ft_memcmp("rrr\n", cmd, 3))
		return ;
	else
	{
		ft_printf("Error\n");
		free_list_2(a);
		free_list_2(b);
		exit (-1);
	}
}

void	operations(char *cmd, t_node **a, t_node **b)
{
	check_op(cmd, a, b);
	if (!ft_memcmp("sa\n", cmd, 3))
		op_sx_s(*a);
	else if (!ft_memcmp("sb\n", cmd, 3))
		op_sx_s(*b);
	else if (!ft_memcmp("ss\n", cmd, 3))
		op_ss_s(*a, *b);
	else if (!ft_memcmp("pa\n", cmd, 3))
		op_px_s(a, b);
	else if (!ft_memcmp("pb\n", cmd, 3))
		op_px_s(b, a);
	else if (!ft_memcmp("ra\n", cmd, 3))
		op_rx_s(a);
	else if (!ft_memcmp("rb\n", cmd, 3))
		op_rx_s(b);
	else if (!ft_memcmp("rr\n", cmd, 3))
		op_rr_s(a, b);
	else if (!ft_memcmp("rra\n", cmd, 4))
		op_rrx_s(a);
	else if (!ft_memcmp("rrb\n", cmd, 4))
		op_rrx_s(b);
	else if (!ft_memcmp("rrr\n", cmd, 4))
		op_rrr_s(a, b);
}

static int	check_result(t_node **a, t_node **b, int n, int argc)
{
	if (argc < 2)
		return (0);
	else if (((*a) && check_sort_2(a) == 1) || (*b))
	{
		if (n == 1)
			ft_printf("KO\n");
		return (0);
	}
	else
	{
		if (n == 1)
			ft_printf("OK\n");
		return (1);
	}
}

void	check_parsing(int argc, char **argv)
{
	if (!argv)
		exit(-1);
	if (verify_argv_2(argv) == -1)
	{
		ft_printf("Error\n");
		free_argv_2(argc, argv);
		exit(-1);
	}
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	char	*cmd;

	argv = clean_argv_2(argc, argv);
	check_parsing(argc, argv);
	a = init_list_2(argv);
	free_argv_2(argc, argv);
	b = NULL;
	if (a)
	{
		cmd = get_next_line(0);
		if (cmd)
			operations(cmd, &a, &b);
		while (cmd)
		{
			free(cmd);
			cmd = get_next_line(0);
			if (cmd)
				operations(cmd, &a, &b);
		}
	}
	check_result(&a, &b, 1, argc);
	ft_free(&a, &b);
	return (0);
}
