/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:14:06 by llapage           #+#    #+#             */
/*   Updated: 2023/06/12 13:49:28 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	save_sol(t_store *store, int i)
{
	store->cur_dist_b = store->cur_dist_b;
	store->distance_b = store->cur_dist_b;
	store->cheaper_sol = i + 1;
	store->distance_a = store->cur_dist_a;
}

void	init_store(t_store *store, int rev)
{
	if (rev == 0)
	{
		store->distance_a = 0;
		store->distance_b = 0;
		store->cheaper_sol = INT_MAX;
	}
	store->cur_dist_a = 0;
	store->cur_dist_b = 0;
	store->found_sol = 0;
}

int	lst_size(t_node **head)
{
	int		i;
	t_node	*cur;

	i = 0;
	if (*head)
	{
		cur = *head;
		while (cur != *head || i == 0)
		{
			i++;
			cur = cur->next;
		}
	}
	return (i);
}

static t_node	*lstadd(t_node **head, char *argv)
{
	t_node	*node;
	t_node	*tmp;

	node = (t_node *) malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->n = ft_atoi_ps(argv);
	if (*head == NULL)
	{
		*head = node;
		(*head)->next = node;
		(*head)->prev = node;
	}
	else
	{
		(*head)->prev->next = node;
		tmp = (*head)->prev;
		(*head)->prev = node;
		if ((*head)->next == *head)
			(*head)->next = node;
		node->next = *head;
		node->prev = tmp;
	}
	return (*head);
}

t_node	*init_list(char **argv)
{
	t_node	*head;
	int		i;

	i = 0;
	head = NULL;
	if (argv)
	{
		while (argv[i])
		{
			if (!lstadd(&head, argv[i]))
			{
				free_list(&head);
				return (NULL);
			}
			i++;
		}
	}
	return (head);
}
