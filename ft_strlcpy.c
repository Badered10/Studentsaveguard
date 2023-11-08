/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:04:36 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/07 21:47:35 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char	*source;
	size_t	source_lenth;

	source = (char *)src;
	source_lenth = ft_strlen(source);
	while (dstsize - 1 > 0)
	{
		*dst++ = *source++;
		dstsize--;
	}
	*dst = '\0';
	return (source_lenth);
}
// int main()
// {
//     char *source = "ABCDEF";
//     char dst[7];
//     char dst1[7];
//     size_t x = strlcpy(dst, source,7);
//     size_t y = ft_strlcpy(dst1, source,7);
//     printf("org number is %zu, org and my string:%s\n",x,dst);
//     printf("copy number is %zu, copy and my string:%s\n",y,dst1);
// }