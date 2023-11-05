/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:54:57 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/04 16:55:00 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"
#include<stdio.h>
int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    const unsigned char *b1;
    const unsigned char *b2;

    b1 = (const unsigned char *)s1;
    b2 = (const unsigned char *)s2;
    n -=1;
    while(n-- > 0 && *b1 - *b2 == 0)
    {
        b1++;
        b2++;
    }
    return(*b1 - *b2);
}
int main()
{
    const char a[6] = "bader";
    const char a2[6] = "badef";
    printf("%d\n",ft_memcmp(a,a2,5));
    printf("%d\n",memcmp(a,a2,5));
}