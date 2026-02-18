/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 18:19:40 by cmauley           #+#    #+#             */
/*   Updated: 2026/02/18 14:13:02 by cmauley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	*stack_to_array(t_node *stack_a, int size);
static void	sort_array(int *tab, int size);

/**
 * @brief transforme stack_a contenant des valeurs quelconques
 * en une stack contenant les rangs de ces valeurs dans l’ordre trié
 */
int	index_stack(t_node *stack_a)
{
	int		*tab;
	t_node	*tmp;
	int		i;
	int		size;

	size = how_many_int(stack_a);
	tab = stack_to_array(stack_a, size);
	if (!tab)
		return (1);
	sort_array(tab, size);
	tmp = stack_a;
	while (tmp)
	{
		i = 0;
		while (i < size && tab[i] != tmp->data)
			i++;
		tmp->data = i;
		tmp = tmp->next;
	}
	free(tab);
	return (0);
}

/**
 * @brief transforme stack_a en tableau d'int
 */
static int	*stack_to_array(t_node *stack_a, int size)
{
	int		*tab;
	int		i;
	t_node	*tmp;

	if (size == 0)
		return (NULL);
	tab = malloc(sizeof(int) * size);
	if (!tab)
		return (NULL);
	tmp = stack_a;
	i = 0;
	while (tmp)
	{
		tab[i] = tmp->data;
		i++;
		tmp = tmp->next;
	}
	return (tab);
}

/**
 * @brief trie avec un bubble sort le tab d'int
 */
static void	sort_array(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	if (!tab || size <= 1)
		return ;
	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab [j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}
