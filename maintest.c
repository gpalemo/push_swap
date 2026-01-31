/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:58:11 by cmauley           #+#    #+#             */
/*   Updated: 2026/01/05 18:18:44 by cmauley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"
#include <stdio.h>

void	print_list(t_node *head)
{
	while (head)
	{
		printf("%d -> ", head->value);
		head = head->next;
	}
	printf("NULL\n");
}

// --- création d’un nœud ---
t_node	*new_node(int value)
{
	t_node *node = malloc(sizeof(t_node));
	node->value = value;
	node->next = NULL;
	return node;
}

int	main(void)
{
	t_node *a;

	// liste : 1 -> 2 -> 3
	a = new_node(1);
	a->next = new_node(2);
	a->next->next = new_node(3);

	printf("Avant swap:\n");
	print_list(a);

	swap(&a, 'a');

	printf("Après swap:\n");
	print_list(a);

	return (0);
}