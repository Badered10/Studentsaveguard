/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:04:36 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/12 11:22:57 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char	*source;
	size_t	source_lenth;

	source = (char *)src;
	source_lenth = ft_strlen(source);
	if (dstsize == 0)
		return (source_lenth);
	dstsize -= 1;
	while ((dstsize > 0) && *source)
	{
		*dst++ = *source++;
		if (dstsize != 0)
			dstsize--;
	}
	*dst = '\0';
	return (source_lenth);
}
// int main()
// {
//     char *source = "lorem ipsum dolor sit amet";
//     char dst[15];
//     char dst1[15];
//     size_t x = strlcpy(dst, source,0);
//     size_t y = ft_strlcpy(dst1, source,0);
//     printf("org number is %zu, org and my string:%s\n",x,dst);
//     printf("copy number is %zu, copy and my string:%s\n",y,dst1);
// }