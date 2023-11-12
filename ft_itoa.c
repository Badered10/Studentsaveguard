/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 11:50:37 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/12 16:49:10 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int lenth(int n)
{
    int res;

    if (n >= 0)
    res = 1;
    else
    res = 2;
    while((n/10) != 0)
    res++;
    return(res);
}

static char *Alloc(int res)
{
    char* str;

    str = (char*)malloc(sizeof(char) * res);
    if(!str)
    return (NULL);
    ft_bzero(str,res);
    return(str);
}

static void fill(char *str, int num , int n)
{
    int j;

    j = 0;
    num -= 1;
    if(n < 0)
    {
     str[0] = '-';
     j++;   
    }
    while(num > j)
    {
        str[num] = n % 10 + '0';
        n /= 10;
        num--;
    }
}

char	*ft_itoa(int n)
{
    char *res;
    int num;

    num = lenth(n);
    res = Alloc(num);
    fill(res,num, n);
    return (res);
}

int main()
{
    int num = -532;

    char *res;
    res = ft_itoa(num);
    printf("%s",res);
}
