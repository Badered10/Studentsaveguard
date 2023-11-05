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

    destination = ((unsigned char *)dst) + len - 1;
    source = ((unsigned char *)src) + len - 1;
    while(len-- > 0)
        *destination-- = *source--;
    return(dst);
}
// int main()
// {
//     char s1[] = "ABCDE";
//     char s2[3];
//     memmove(s2,s1,3);
//     printf("%s",s2);
// }