/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:15:36 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/17 23:09:31 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_bytes;
	void	*ptr;

	if (!size || !count)
		return (malloc(0));
	if (size == SIZE_MAX || count == SIZE_MAX || (size * count) >= SIZE_MAX)
		return (NULL);
	total_bytes = count * size;
	ptr = (void *)malloc(total_bytes);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total_bytes);
	return (ptr);
}
/*
int	main(void)
{
	char	*c;

	c = calloc(SIZE_MAX, SIZE_MAX);
	printf("'%p'", c);
}
*/
