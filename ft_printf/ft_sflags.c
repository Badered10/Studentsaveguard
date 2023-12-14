/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sflags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 08:27:32 by baouragh          #+#    #+#             */
/*   Updated: 2023/12/14 18:30:14 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int ft_sflags(char *string, char *res)
{
    f nes;

    nes.display = 0; 
    nes.point = 0;
    nes.mince = 0;
    nes.count = 0;
    nes.zero = 0;
    while(*string == '-' && *(string + 1))
    {
        nes.mince = 1;
        string++;
    }
    if(res)
    nes.len = (int)ft_strlen(res);
    else
    nes.len = 0;
    while (*string == '0' && *(string + 1))
    {
        nes.zero = 1;
        string++;
    }
    if(ft_isdigit(*string))
        nes.spaces = ft_atoi(string);
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
            nes.display = ft_atoi(string);
            if (nes.display > nes.len && nes.len != 0)
            nes.display = nes.len;
            if (nes.spaces > nes.display)
                nes.spaces -= nes.display;
            else
                nes.spaces = 0;
        }
    }
    else if (nes.point != 1)
    {
        if (nes.len != 0)
        nes.display = nes.len;
        nes.spaces -= nes.display; 
    }
        if (nes.display == nes.spaces)
            nes.spaces = 0;
    if (nes.mince == 1) 
    {
        nes.count += ft_putnstr_fd(res,1,nes.display);
         if (nes.len != 0)
        while ((nes.spaces)-- > 0 )
            nes.count += write(1," ",1);
            else
            while ((nes.spaces)-- > 0 )
            nes.count += write(1," ",1);
        return (nes.count);
    }
    else
    {
        if (nes.len != 0)
        while ((nes.spaces)-- > 0 )
            nes.count += write(1," ",1);
        else if (nes.len == 0 && nes.zero == 1)
        while ((nes.spaces)-- > 0 )
            nes.count += write(1,"0",1);
        else
            while ((nes.spaces)-- > 0 )
            nes.count += write(1," ",1);
         nes.count += ft_putnstr_fd(res,1,nes.display);
        return (nes.count);
    }
}
