/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 20:52:05 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/03 20:52:07 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>
#include"libft.h"
void *ft_memchr(const void *s, int c)
{
    const char *initial;
    const char *founded_p;

    initial = s;
    founded_p = ft_strchr(initial, c);
    if(founded_p == NULL)
    return (NULL);
     return ((void*)s + (founded_p - initial));
    
}

int main()
{
    memcpy(vo)
    const char str[6] = "hello";
    char *ret;
    ret = ft_memchr(str, 'e');
    printf("%s",ret);
}