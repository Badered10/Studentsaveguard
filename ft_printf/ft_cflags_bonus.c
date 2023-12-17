/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cflags_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:57:29 by baouragh          #+#    #+#             */
/*   Updated: 2023/12/17 22:23:06 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void ft_assister(char *string,f *nes)
{
    if(ft_isdigit(*string))
    {
        nes->spaces = ft_atoi(string);
        if (nes->spaces > nes->len)
        nes->spaces = nes->spaces - nes->len;
        else 
        nes->spaces = 0;
    }
    else
       nes->spaces = 0;
    while(ft_isdigit(*string))
        string++;
    if (nes->mince == 0)
    {
        while (((nes->spaces)-- > 0))
            nes->count += write(1," ",1);
                nes->count += ft_putchar_fd(nes->d,1);
    }
    else
    {
            nes->count += ft_putchar_fd(nes->d,1);
        while (((nes->spaces)-- > 0))
            nes->count += write(1," ",1);
    }
}

int ft_cflags(char *string, int x)
{
    f nes;
    nes.mince = 0;
    nes.count = 0;
    while(*string == '-' && *(string + 1))
    {
        nes.mince = 1;
        string++;
    }
    nes.d = x;
    nes.len = 1;
    return (ft_assister(string,&nes),nes.count);
    
}
