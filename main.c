/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:32:20 by cmauley           #+#    #+#             */
/*   Updated: 2026/02/02 23:26:15 by cmauley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	main(int ac, char **av)
{
	char	**str;

	str = NULL;
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
	// push_swap
}
