/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 20:41:30 by llapage           #+#    #+#             */
/*   Updated: 2023/06/12 15:15:23 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_argv(char **argv)
{
	int	i;

	if (argv)
	{
		i = 0;
		while (argv[i])
			free(argv[i++]);
		free(argv);
	}
}

void	free_list(t_node **head)
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

int	ft_abs(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

long long	ft_atoi_ps(const char *str)
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

int	check_sort(t_node **a)
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
