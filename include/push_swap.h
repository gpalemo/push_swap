/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 16:01:23 by cmauley           #+#    #+#             */
/*   Updated: 2026/02/03 19:33:38 by cmauley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/include_lib/libft.h"

# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
}					t_node;
// swap
void	swap(t_node **head, char stack);
void	ss(t_node **head_a, t_node **head_b);
// push
void	pa(t_node **head_a, t_node **head_b);
void	pb(t_node **head_a, t_node **head_b);
// rotate
void	rr(t_node **head_a, t_node **head_b);
void	rrr(t_node **head_a, t_node **head_b);
// write output
void	write_swap(char stack);
void	write_rotate(char stack);
void	write_rev_rotate(char stack);
int		write_error(void);

#endif
