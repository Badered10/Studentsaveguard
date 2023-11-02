/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:00:26 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/01 13:00:33 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<ctype.h>
#include<stdio.h>

void *ft_memset(void *b, int c, size_t len)
{
     char *temp;
    temp = (char *)b;
    size_t i ;

    i = 0;
    while(i < len)
    {
        temp[i] = c;
        i++;
    }
    return (b);
}

int main()
{
    char s[6] = "hello";
    printf(" %s\n",ft_memset(s + 2, '.', sizeof(char) * 2));
}