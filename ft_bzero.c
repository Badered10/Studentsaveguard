/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:50:13 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/02 14:50:17 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"
#include<ctype.h>
#include<stdio.h>
#include<strings.h>
void *ft_bzero(void *b, size_t n)
{
    char *str;
    str = (char *) b;
    size_t i;

    i = 0;
    while(i < n)
    {
        ft_memset(&str[i],0,sizeof(char));
        i++;
    }
    return (str);
}

int main()
{
    char s[7] = "bader";
    char s2[7] = "bader";
    printf("this is before : %s \n", s);
    ft_bzero(s,sizeof(char) * 5);
    printf("this is after : %s\n", s);

    printf("this is before : %s \n", s2);
    bzero(s2,sizeof(char) * 5);
    printf("this is after : %s\n", s2);
    
}
