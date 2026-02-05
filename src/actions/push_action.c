/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_action.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 16:35:08 by cmauley           #+#    #+#             */
/*   Updated: 2026/02/05 15:39:54 by cmauley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	push(t_node **src, t_node **dst);

void	pa(t_node **head_a, t_node **head_b)
{
	push(head_b, head_a);
	write(1, "pa\n", 3);
}

void	pb(t_node **head_a, t_node **head_b)
{
	push(head_a, head_b);
	write(1, "pb\n", 3);
}

/**
 * @brief push : déplacer le premier int d'une stack au sommet de l'autre (si déplace sur A: pa; si déplace sur B; pb).
 *
 * @param src stack 1
 * @param dst stack 2
 */
static void	push(t_node **src, t_node **dst)
{
	t_node	*tmp;

	if (*src == NULL)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dst;
	*dst = tmp;
}
