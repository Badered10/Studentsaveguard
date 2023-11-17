/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:31:16 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/17 22:36:44 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t _size)
{
	char	*source;
	char	*destination;

	source = (char *)src;
	destination = (char *)dst;
	if (!destination && !source)
		return (dst);
	while (_size--)
		*destination++ = *source++;
	return (dst);
}
/*
int	main(void)
{
	char ptr[]= "k";
	char *str =NULL;
		ft_memcpy(ptr,str,1);
	printf("ptr =%p, \t str =%p",ptr,str);
}
*/
