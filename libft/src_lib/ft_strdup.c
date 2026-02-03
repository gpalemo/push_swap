/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 23:13:43 by cmauley           #+#    #+#             */
/*   Updated: 2026/02/02 21:42:43 by cmauley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;

	dest = (char *) malloc(ft_strlen(src) + 1);
	if (!dest)
		return (NULL);
	ft_memcpy(dest, src, ft_strlen(src) + 1);
	return (dest);
}

/*int	main(void)
{
	char	*src = "Hello World";
	char	*copy;

	copy = ft_strdup(src);
	printf("Source = %s\n", src);
	printf("Copie = %s\n", copy);

	free(copy);
	return (0);
}*/
