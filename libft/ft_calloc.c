/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:15:36 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/18 18:05:59 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_bytes;
	void	*ptr;

	if (count && (SIZE_MAX / count < size))
		return (NULL);
	total_bytes = count * size;
	ptr = (void *)malloc(total_bytes);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total_bytes);
	return (ptr);
}