/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 23:52:52 by cmauley           #+#    #+#             */
/*   Updated: 2026/02/10 15:52:52 by cmauley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	sort_small_stack(t_node **stack_a, t_node **stack_b);
static void	sort_big_stack(t_node **stack_a, t_node **stack_b);

int	sort(t_node *stack_a, t_node *stack_b)
{
	int	size;

	size = how_many_int(stack_a);
	if (a_is_sorted(stack_a) == 0)
		return (1);
	if (size <= 5)
		sort_small_stack(stack_a, stack_b);
	else
		sort_big_stack(stack_a, stack_b);
	return (0);
}

static void	sort_small_stack(t_node **stack_a, t_node **stack_b)
{
	if (how_many_int(*stack_a) <= 1)
		return ;
	if (how_many_int(*stack_a) == 2)
	{
		if ((*stack_a)->data > (*stack_a)->next->data)
			swap(stack_a, 'a');
	}
	if (how_many_int(*stack_a) == 3)
		sort_three(*stack_a);
	if (how_many_int(*stack_a) == 4)
		sort_four(stack_a, stack_b);
	if (how_many_int(*stack_a) == 5)
		sort_five(stack_a, stack_b);
	return ;
}

static void	sort_big_stack(t_node **stack_a, t_node **stack_b)
{

}
