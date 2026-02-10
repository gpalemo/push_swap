/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_or_less.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 19:34:50 by cmauley           #+#    #+#             */
/*   Updated: 2026/02/10 19:48:14 by cmauley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		get_index_min(t_node *stack);
void	push_min_to_b(t_node **stack_a, t_node **stack_b);

void	sort_three(t_node *stack_a)
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

void	sort_four(t_node **stack_a, t_node **stack_b)
{
	push_min_to_b(stack_a, stack_b);
	sort_three(*stack_a);
	pa(stack_b, stack_a);
}

void	sort_five(t_node **stack_a, t_node **stack_b)
{
	push_min_to_b(stack_a, stack_b);
	push_min_to_b(stack_a, stack_b);
	sort_three(*stack_a);
	pa(stack_b, stack_a);
	pa(stack_b, stack_a);
}

void	push_min_to_b(t_node **stack_a, t_node **stack_b)
{
	int	index;
	int	size;
	int	i;

	index = get_index_min(*stack_a);
	size = how_many_int(*stack_a);
	if (index <= size / 2)
	{
		i = index;
		while (i > 0)
		{
			rotate(stack_a, 'a');
			i--;
		}
	}
	else
	{
		i = size - index;
		while (i > 0)
		{
			rev_rotate(stack_a, 'a');
			i--;
		}
	}
	pb(stack_a, stack_b);
}

int	get_index_min(t_node *stack)
{
	t_node	*tmp;
	int		min;
	int		min_index;
	int		i;

	if (stack == NULL)
		return (-1);
	tmp = stack;
	min = tmp->data;
	min_index = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->data < min)
		{
			min = tmp->data;
			min_index = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (min_index);
}
