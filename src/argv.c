/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 13:09:34 by llapage           #+#    #+#             */
/*   Updated: 2023/06/13 16:48:24 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	matrix_len(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

int	check_tab(int *tab, int len)
{
	int		i;
	int		j;
	long	n;

	j = 0;
	i = 0;
	while (i < len)
	{
		n = tab[i];
		j = i + 1;
		while (j < len)
		{
			if (n == tab[j])
			{
				free(tab);
				return (-1);
			}
			j++;
		}
		i++;
	}
	free(tab);
	return (0);
}

static int	check_duplicates(char **argv)
{
	int			*tab;
	int			i;
	long long	n;

	i = 0;
	tab = malloc(sizeof(int *) * matrix_len(argv));
	if (!tab)
		return (-1);
	while (argv[i])
	{
		n = ft_atoi_ps(argv[i]);
		if (ft_strlen(argv[i]) > 11 || n > 2147483647 || n < -2147483648)
		{
			free(tab);
			return (-1);
		}
		tab[i] = ft_atoi_ps(argv[i]);
		i++;
	}
	if (check_tab(tab, matrix_len(argv)) == -1)
		return (-1);
	return (0);
}

int	verify_argv(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		if (argv[i][0] == '-' || argv[i][0] == '+')
		{
			j++;
			if (!argv[i][j])
				return (-1);
		}
		while (argv[i][j])
		{
			if ((argv[i][j] < '0' || argv[i][j] > '9'))
				return (-1);
			j++;
		}
		i++;
	}
	if (check_duplicates(argv) == -1)
		return (-1);
	return (0);
}

char	**clean_argv(int argc, char **argv)
{
	char	**new;
	int		i;

	new = NULL;
	i = 0;
	if (argc == 2)
	{
		while (argv[i + 1])
		{
			new = ft_split(argv[i + 1], ' ');
			i++;
		}
	}
	else
		return (&argv[1]);
	return (new);
}
