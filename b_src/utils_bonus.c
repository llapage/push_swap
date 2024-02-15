/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:56:29 by llapage           #+#    #+#             */
/*   Updated: 2023/06/14 10:19:52 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_argv_2(int argc, char **argv)
{
	int	i;

	if (argv && argc == 2)
	{
		i = 0;
		while (argv[i])
			free(argv[i++]);
		free(argv);
	}
}

void	free_list_2(t_node **head)
{
	t_node	*cur;
	t_node	*next;
	int		done;

	done = 0;
	if (*head)
	{
		cur = *head;
		while (cur != *head || done == 0)
		{
			done = 1;
			next = cur->next;
			free(cur);
			cur = next;
		}
	}
}

long long	ft_atoi_ps_2(const char *str)
{
	long long	negative;
	int			i;
	long long	result;

	negative = 1;
	i = 0;
	result = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative = -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] < 48 || 57 < str[i])
			break ;
		else
			result = (result * 10) + (int)(str[i] - '0');
		i++;
	}
	return (result * negative);
}

int	check_sort_2(t_node **a)
{
	t_node	*cur;
	int		done;

	done = 0;
	cur = (*a);
	while ((cur) != (*a) || done == 0)
	{
		done = 1;
		if (cur->next != (*a))
		{
			if (cur->n > cur->next->n)
			{
				return (1);
			}
		}
		cur = cur->next;
	}
	return (0);
}
