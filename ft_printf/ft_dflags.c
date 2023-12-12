/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dflag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 18:00:25 by baouragh          #+#    #+#             */
/*   Updated: 2023/12/12 11:18:17 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int d_flags(char *string, va_list args)
{
    f nes;

    while(*string == '0' && *(string + 1))
    {
        nes.zero = 1;
        string++;
    }
    while(*string == '-' && *(string + 1))
    {
        nes.zero = 0;
        nes.mince = 1;
        string++;
    }
    nes.d = va_arg(args,int);
    nes.len = (int)ft_strlen(ft_itoa(nes.d));
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
    if (*string == '.' && *(string + 1))
    {
        nes.point = 1;
        string++;
        if(ft_isdigit(*string))
        {                      
            nes.zeros = ft_atoi(string);   
            if (nes.zeros > nes.len)
            nes.zeros = nes.zeros - nes.len;
            else
            nes.zeros = 0;
            nes.spaces = nes.spaces - nes.zeros;
        }
        // nes.width = nes.zeros + nes.spaces;
    }
    else if (nes.zero == 1 && nes.point != 1 && nes.mince != 1)
            nes.zeros == nes.spaces;
        if (nes.zeros == nes.spaces)
            nes.spaces = 0;
    if (nes.mince == 1)
    {
        while ((nes.zeros)-- > 0)
            nes.count += write(1,"0",1);
        nes.count += ft_putnbr_fd(nes.d,1);
        while ((nes.spaces)-- > 0 )
            nes.count += write(1," ",1);
        return (nes.count);
    }
    else if (nes.point == 1)
    {
        while ((nes.spaces)--)
            nes.count += write(1," ",1);
        while ((nes.zeros)--)
            nes.count += write(1,"0",1);
        nes.count += ft_putnbr_fd(nes.d,1);
        return (nes.count);
    }
    else
    {
        while ((nes.zeros)--)
            nes.count += write(1,"0",1);
        nes.count += ft_putnbr_fd(nes.d,1);
        return (nes.count);
    }
}
