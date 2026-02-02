/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_action.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 16:41:55 by cmauley           #+#    #+#             */
/*   Updated: 2026/02/02 23:35:41 by cmauley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

// swap : échanger les deux premiers int d'une stack (si A: sa; si B: sb; si les deux: ss).
void	swap(t_node **head, char stack)
{
	t_node	*top;
	t_node	*second;

	top = *head;
	second = (*head)->next;
	top->next = (*head)->next->next;
	second->next = top;
	*head = second;
	if (stack != 'c')
		write_swap(stack);
}

void	ss(t_node **head_a, t_node **head_b)
{
	swap(head_a, 'c');
	swap(head_b, 'c');
	write (1, "ss\n", 3);
}
