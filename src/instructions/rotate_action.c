/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 22:56:23 by cmauley           #+#    #+#             */
/*   Updated: 2026/02/05 18:16:22 by cmauley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate(t_node **head, char stack);
void	rev_rotate(t_node **head, char stack);

void	rr(t_node **head_a, t_node **head_b)
{
	rotate(head_a, 'c');
	rotate(head_b, 'c');
	write(1, "rr\n", 3);
}

void	rrr(t_node **head_a, t_node **head_b)
{
	rev_rotate(head_a, 'c');
	rev_rotate(head_b, 'c');
	write(1, "rrr\n", 4);
}

/**
 * @brief rotate : décaler tous les int d'une stack vers le haut, en passant alors le premier 
 * en dernier (si A: ra; si B: rb; si les deux: rr).
 */
void	rotate(t_node **head, char stack)
{
	t_node	*top_cpy;
	t_node	*current;

	current = *head;
	top_cpy = *head;
	while (current->next != NULL)
	{
		current = current->next;
	}
	*head = (*head)->next;
	current->next = top_cpy;
	top_cpy->next = NULL;
	if (stack != 'c')
		write_rotate(stack);
}

/**
 * @brief reverse rotate : décaler tous les int d'une stack vers le bas, 
 * en passant alors le dernier en premier (si A: rra; si B: rrb; si les deux: rrr).
 */
void	rev_rotate(t_node **head, char stack)
{
	t_node		*top;
	t_node		*bottom;
	t_node		*current;

	top = *head;
	current = *head;
	while (current->next->next != NULL)
		current = current->next;
	bottom = current->next;
	bottom->next = top;
	current->next = NULL;
	*head = bottom;
	if (stack != 'c')
		write_rev_rotate(stack);
}
