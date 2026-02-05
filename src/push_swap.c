/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:32:20 by cmauley           #+#    #+#             */
/*   Updated: 2026/02/05 18:15:04 by cmauley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_node	*make_list(char **av, int start);
static void		create_and_sort(char **tab, int start);

int	main(int ac, char **av)
{
	char	**str;

	str = NULL;
	if (ac == 2)
	{
		str = ft_split(av[1], ' ');
		if (is_error(str, 0) == 1)
		{
			//free tab
			return (1);
		}
		create_and_sort(str, 0);
		//free tab
	}
	else if (ac > 2)
	{
		if (is_error(av, 1) == 1)
			return (1);
		create_and_sort(av, 1);
	}
	return (0);
}

/**
 * @brief fonction qui crée une liste d'int a partir d'un double tableau
 *
 * @param tab soit av, soit str
 * @param start flag qui indique si il y plusieurs arguments ou non
 * (si un split a eu lieu ou non)
 * @return t_node : la liste d'int
 */
static t_node	*make_list(char **tab, int start)
{
	t_node	*head;
	t_node	*current;
	int		j;

	head = malloc(sizeof(t_node));
	if (!head)
		return (NULL);
	head->data = ft_atoi(tab[start]);
	head->next = NULL;
	j = start + 1;
	current = head;
	while (tab[j])
	{
		current->next = malloc(sizeof(t_node));
		if (!current->next)
			return (NULL);
		current = current->next;
		current->data = ft_atoi(tab[j]);
		j++;
	}
	current->next = NULL;
	return (head);
}

/**
 * @brief fonction qui crée la stack a (liste d'int) et stack b (liste vide), 
 * les trie et free stack a
 *
 * @param tab soit av, soit str
 * @param start flag qui indique si il y plusieurs arguments ou non
 * (si un split a eu lieu ou non)
 */
static void	create_and_sort(char **tab, int start)
{
	t_node	*stack_a;
	t_node	*stack_b;
	
	stack_a = make_list(tab, start);
	stack_b = NULL;
	//sort
	free_list(stack_a);
}
