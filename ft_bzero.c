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