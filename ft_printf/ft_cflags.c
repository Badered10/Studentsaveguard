/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cflags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:57:29 by baouragh          #+#    #+#             */
/*   Updated: 2023/12/12 20:29:20 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int ft_cflags(char *string, int x)
{
    f nes;
    static int y = 1;

    nes.spaces = 0;
    nes.count = 0;
    while(*string == '-' && *(string + 1))
        string++;
    nes.d = x;
    nes.len = 1;
    if(ft_isdigit(*string))
    {
        nes.spaces = ft_atoi(string);
        if (nes.spaces > nes.len)
        nes.spaces = nes.spaces - nes.len;
        else 
        nes.spaces = 0;
    }
    else
       nes.spaces = 0;
    while(ft_isdigit(*string))
        string++;
    while (((nes.spaces)-- > 0) && y!= 1)
        nes.count += write(1," ",1);
        nes.count += ft_putchar_fd(nes.d,1);
    y++;
        return (nes.count);
}