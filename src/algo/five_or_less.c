/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_or_less.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 19:34:50 by cmauley           #+#    #+#             */
/*   Updated: 2026/02/08 21:20:14 by cmauley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	sort_two(t_node	*stack_a);
static void	sort_three(t_node *stack_a);
// si taille <= 1 -> return
// si taille == 2 -> sort_two(stack_a)
// si taille == 3 -> sort_three(stack_a)
// si taille == 4 -> push_min_to_b(stack_a, stack_b, 1), sort_three(stack_a), push_back_from_b(stack_a, stack_b)
// si taille == 5 -> push_min_to_b(stack_a, stack_b, 2), sort_three(stack_a), push_back_from_b(stack_a, stack_b)

void	sort_small_stack(t_node **stack_a, t_node **stack_b)
{
	if (how_many_int(stack_a) <= 1)
		return ;
	if (how_many_int(stack_a) == 2)
		sort_two(stack_a);
	if (how_many_int(stack_a) == 3)
		sort_three(stack_a);
	
}
static void	sort_two(t_node	*stack_a)
{
	if (stack_a->data > stack_a->next->data)
	{
		swap(&stack_a, 'a');
	}
}

static void	sort_three(t_node *stack_a)
{
	int	first = stack_a->data;
	int	second = stack_a->next->data;
	int	third = stack_a->next->next->data;

	if (first < third && third < second)
	{
		swap(&stack_a, 'a');
		rotate(&stack_a, 'a');
	}
	else if (second < first && first < third)
		swap(&stack_a, 'a');
	else if (second < third && third < first)
		rotate(&stack_a, 'a');
	else if (third < first && first < second)
		rev_rotate(&stack_a, 'a');
	else if (third < second && second < first)
	{
		swap(&stack_a, 'a');
		rev_rotate(&stack_a, 'a');
	}
}

static void	push_min_to_b(t_node *stack_a, t_node *stack_b, int )