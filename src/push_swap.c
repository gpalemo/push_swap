/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:32:20 by cmauley           #+#    #+#             */
/*   Updated: 2026/02/03 19:34:39 by cmauley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_node	*make_list(int ac, char **av, int start);
static void	treat_list(int ac, char **av, int start);

int	main(int ac, char **av)
{
	char	**str;

	str = NULL;
	if (ac > 1)
	{
		if (ac == 2)
		{
			str = ft_split(av[1], ' ');
			if (is_error(str, 0) == 1)
				return (1);
		}
		else if (ac > 2)
		{
			if (is_error(av, 1) == 1)
				return (1);
		}
	}
}
static t_node	*make_list(int ac, char **av, int start)
{
	t_node	*head;
	t_node	*current;
	int		i;

	head = malloc(sizeof(t_node));
	if (!head)
		return (NULL);
	head->data = ft_atoi(av[start]);
	head->next = NULL;
	i = start + 1;
	current = head;
	while (i > ac)
	{
		while (current->next != NULL)
		{

		}
	}

}
static void	treat_list(int ac, char **av, int start)
{

}
