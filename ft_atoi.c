/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:53:19 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/06 17:53:21 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

int ft_atoi(const char *str)
{
    char *var = (char *)str;
    int res = 0;
    int signe = 1;
    if(*var == '-' || *var == '+')
    {
        if(*var == '-')
        signe *=-1;
        var++;
    }
    while(*var && *var >= '0' && *var <= '9')
    {
        res = res * 10 + (*var - '0');
        var++;
    }
    return(res * signe);
}
// int main()
// {
//     const char *str ="j";
//     int x = ft_atoi(str);
//     printf("%d",x);
// }