/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_than_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 00:52:44 by cmauley           #+#    #+#             */
/*   Updated: 2026/02/18 17:17:54 by cmauley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	get_max_bits(int size);

/**
 * @brief Trie la pile en utilisant le radix sort sur les index.
* Pour chaque bit : les 0 sont push dans B, les 1 sont rotate dans A,
* puis tout est renvoyé dans A.
 */
int	radix_sort(t_node **stack_a, t_node **stack_b)
{
	int	size;
	int	max_bits;
	int	i;
	int	j;

	index_stack(*stack_a);
	size = how_many_int(*stack_a);
	max_bits = get_max_bits(size);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*stack_a)->data >> i) & 1) == 0)
				pb(stack_a, stack_b);
			else
				rotate(stack_a, 'a');
			j++;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		i++;
	}
	return (0);
}

/**
 * @brief donne le nombre de radix a effectuer selon
 * le nombre de decalage à droite
 */
static int	get_max_bits(int size)
{
	int	max;
	int	bits;

	max = size - 1;
	bits = 0;
	while ((max >> bits != 0))
		bits++;
	return (bits);
}
