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
    void *pt;
    pt = b;
    int i;

    i = 0;
    while (len <= 0 && pt )
    {
        pt = 'c';
        pt++;
        i++;
    }
    i == -i; 
    return ((void *)b - i);
}

int main()
{
    char *s = "hello";
    printf(" ",);
}