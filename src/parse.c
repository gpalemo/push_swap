/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:02:38 by cmauley           #+#    #+#             */
/*   Updated: 2026/02/02 23:33:53 by cmauley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	is_number(char **str, int start)
{
	int	i;
	int	j;

	i = 0;
	j = start;
	if (!str[j])
		return (1);
	while (str[j])
	{
		while (str[j][i])
		{
			if ((str[j][i] == '+' || str[j][i] == '-')
				&& ft_isdigit(str[j][i + 1]) == 1)
				i++;
			if (ft_isdigit(str[j][i]) == 0)
				return (1);
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}

static int	is_duplicate(char **str, int start)
{
	int	k;
	int	j;
	int	nbr;
	int	tmp;

	j = start;
	while (str[j])
	{
		k = j + 1;
		nbr = ft_atoi(str[j]);
		while (str[k])
		{
			tmp = ft_atoi(str[k]);
			if (tmp == nbr)
				return (1);
			k++;
		}
		j++;
	}
	return (0);
}

static int	int_limit_check(char **str, int start)
{
	long	nbr;
	int		j;

	j = start;
	while (str[j])
	{
		nbr = ft_atoi(str[j]);
		if (str[j] < -2147483648 || str[j] > 2147483647)
			return (1);
		j++;
	}
	return (0);
}

int	is_one_number(char **str)
{
	int	j;

	while (str[j])
		j++;
	return (j);
}

int	is_error(char **str, int start)
{
	if (is_one_number(str) <= 1)
		return (write_error());
	if (is_number(str, start) == 1)
		return (write_error());
	if (int_limit_check(str, start) == 1) // avant is_duplicate pour eviter confusion atoi de >intmax et <intmin
		return (write_error());
	if (is_duplicate(str, start) == 1)
		return (write_error());
	return (0);
}
