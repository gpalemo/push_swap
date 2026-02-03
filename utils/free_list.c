/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 19:16:47 by cmauley           #+#    #+#             */
/*   Updated: 2026/02/03 19:20:07 by cmauley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_list(t_node *list)
{
	t_node	*copy;
	t_node	*current;

	copy = list;
	while (copy != NULL)
	{
		current = copy->next;
		free(copy);
		copy = current;
	}
}
