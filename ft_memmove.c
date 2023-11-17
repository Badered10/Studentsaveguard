/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 22:47:22 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/17 22:43:33 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
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
/*
#include <string.h>

int	main(void)
{
	char	*src;
	char	*dest;

   src = "NULL";
	dest = NULL;
	//printf("before memove s2 is:%s\n",s2); CDEFGH
	ft_memmove(dest,src,0);
	printf("\n\ns2 is:%s\n",dest);
}
*/
