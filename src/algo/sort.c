/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 23:52:52 by cmauley           #+#    #+#             */
/*   Updated: 2026/02/08 00:52:18 by cmauley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	sort(t_node *stack_a, t_node *stack_b)
{
	if (a_is_sorted(stack_a) == 0)
		return (1);
	if (how_many_int(stack_a) <= 5)
		sort_small_stack(stack_a, stack_b);
	if (how_many_int(stack_a) > 5)
		sort_big_stack(stack_a, stack_b);
}