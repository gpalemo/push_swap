/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 19:16:47 by cmauley           #+#    #+#             */
/*   Updated: 2026/02/05 17:55:21 by cmauley          ###   ########.fr       */
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

void	free_tab(char **str)
{
	int j;
	
	j = 0;
	while (str[j])
	{
		free (str[j]);
		j++;
	}
	free (str);
}
