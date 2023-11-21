/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:26:03 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/21 13:54:20 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*temp;
	size_t	i;

	temp = (char *)b;
	i = 0;
	while (i < len)
		temp[i++] = c;
	return (b);
}
void	ft_bzero(void *b, size_t n)
{
	ft_memset(b, 0, n);
}

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

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*source;
	unsigned char	*destination;

	source = (unsigned char *)src;
	destination = (unsigned char *)dst;
	if (!destination && !source)
		return (NULL);
	if ((destination == source) && n)
		return (dst);
	while (n--)
		*destination++ = *source++;
	return (dst);
}

void *ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*destination;
	unsigned char	*source;

	if (!src && !dst)
		return (NULL);
	if (src > dst)
	{
		ft_memcpy(dst, src, len);
		return (dst);
	}
	destination = (unsigned char *)dst;
	source = (unsigned char *)src;
	while (len != 0)
	{
		destination[len - 1] = source[len - 1];
		len--;
	}
	return ((void *)destination);
}
