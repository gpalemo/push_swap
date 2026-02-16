/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:26:57 by cmauley           #+#    #+#             */
/*   Updated: 2026/02/16 19:50:32 by cmauley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	write_swap(char stack)
{
	if (stack == 'a')
		write (1, "sa\n", 3);
	else if (stack == 'b')
		write (1, "sb\n", 3);
}

void	write_rotate(char stack)
{
	if (stack == 'a')
		write(1, "ra\n", 3);
	else if (stack == 'b')
		write (1, "rb\n", 3);
}

void	write_rev_rotate(char stack)
{
	if (stack == 'a')
		write(1, "rra\n", 4);
	else if (stack == 'b')
		write(1, "rrb\n", 4);
}

int	write_error(void)
{
	write (2, "Error\n", 6);
	return (1);
}
