/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:15:36 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/06 18:15:37 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"
void *ft_calloc(size_t count, size_t size)
{
    int total_bytes;
    void *ptr;

    total_bytes = count * size;
    ptr = malloc(total_bytes);
    if(!ptr)
    return(NULL);
    ft_bzero(ptr,total_bytes);
    return(ptr);
}
int main()
{
    int *arr;
    int n = 5;
    arr = calloc(n,sizeof(int));
    printf("%lu",sizeof(arr));
}
