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
#include "libft.h"
#include<stdio.h>
void *ft_memset(void *b, int c, size_t len)
{
    char *temp;
    temp = (char *)b;
    size_t i ;

    i = 0;
    while(i < len)
        temp[i++] = c;

    return (b);
}   
int main ()
{
    char arr[10];
    char arr1[10];
    memset(arr,'/190', sizeof(arr));
    printf("before : %s\n",arr);
    printf("before : %p\n",arr);
    ft_memset(arr1,'/190', sizeof(arr1));
    printf("after : %s\n", arr1);
    printf("after : %p\n", arr1);
    // printf("before : %s\n",arr1);
}