/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:04:45 by llapage           #+#    #+#             */
/*   Updated: 2023/06/13 15:05:22 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_node	*lstadd_2(t_node **head, char *argv)
{
	t_node	*node;
	t_node	*tmp;

	node = (t_node *) malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->n = ft_atoi_ps_2(argv);
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

t_node	*init_list_2(char **argv)
{
	t_node	*head;
	int		i;

	i = 0;
	head = NULL;
	if (argv)
	{
		while (argv[i])
		{
			if (!lstadd_2(&head, argv[i]))
			{
				free_list_2(&head);
				return (NULL);
			}
			i++;
		}
	}
	return (head);
}
