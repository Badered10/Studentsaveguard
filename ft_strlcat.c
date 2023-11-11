/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:41:41 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/11 14:08:53 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	needed;
	size_t	i;
	size_t	limite;

	i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	needed = src_len + dstsize;
	if (dstsize <= dst_len)
		return (needed);
	limite = dstsize - 1;
	while (src[i] && dst_len < limite--)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

// int main()
// {
// 	char dest[12]= "0123456789";
// 	char * src = (char *)"1";
// 	int x = ft_strlen(src);
// 	printf("mine :%zu\t%s x is = %d\n",ft_strlcat(dest, src, 11),dest,x);
// }
