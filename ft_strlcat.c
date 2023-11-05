/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:41:41 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/05 15:41:44 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include"libft.h"

size_t ft_strlcat(char * dst, const char *src, size_t dstsize)
{
    char *source;
    size_t dst_lenth;
    size_t source_lenth;
    size_t free_places;

    source = (char *)src;
    dst_lenth = ft_strlen(dst);
    source_lenth = ft_strlen(source);
    dst += dst_lenth;
    free_places = dstsize - 1 - dst_lenth;

    while(free_places-- > 0)
        *dst++ = *source++;
    *dst = '\0';
    return(dst_lenth + source_lenth);
}
// int main()
// {
//     char str1[9]="hello";
//     char str2[4]="abc";
//     size_t x = ft_strlcat(str1,str2,9);
//     printf("x is:%zu, \t string is:%s",x,str1);
// }
