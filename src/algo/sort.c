/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 23:52:52 by cmauley           #+#    #+#             */
/*   Updated: 2026/02/16 18:57:11 by cmauley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	sort_small_stack(t_node **stack_a, t_node **stack_b);

int	sort(t_node **stack_a, t_node **stack_b)
{
	int	size;

	size = how_many_int(*stack_a);
	if (is_a_sorted(*stack_a) == 0)
		return (0);
	if (size <= 5)
		sort_small_stack(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
	return (0);
}

static void	sort_small_stack(t_node **stack_a, t_node **stack_b)
{
	int	nb;

	nb = how_many_int(*stack_a);
	if (nb <= 1)
		return ;
	if (nb == 2)
	{
		if ((*stack_a)->data > (*stack_a)->next->data)
			swap(stack_a, 'a');
	}
	if (nb == 3)
		sort_three(stack_a);
	if (nb == 4)
		sort_four(stack_a, stack_b);
	if (nb == 5)
		sort_five(stack_a, stack_b);
	return ;
}
