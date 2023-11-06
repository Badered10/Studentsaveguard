/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 22:47:22 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/04 22:47:23 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

void *ft_memmove(void *dst, const void *src, size_t len)
{
    unsigned char *destination;
    unsigned char *source;
    size_t  to_move;

    to_move = ft_strlen(dst) - 1;
    if(src + len < dst)
    {
        ft_memcpy(dst,src,len);
        return(dst);
    }
    destination = ((unsigned char *)dst);
    source = ((unsigned char *)src);
    destination += to_move;
    source += to_move;
    while(len-- > 0)
    {
        *destination-- = *source--;
    }
    return(dst);
}
// int main()
// {
//     char source[] = "ABCD";
//     char *dest = source + 2;
//     //printf("before memove s2 is:%s\n",s2);


//     ft_memmove(dest,source,2);
//     printf("\n\ns2 is:%s\n",dest);
// }
