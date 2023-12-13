/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pflags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:40:40 by baouragh          #+#    #+#             */
/*   Updated: 2023/12/13 17:35:32 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int ft_pflags(char *string, void* res)    // "%-010p"
{
    f nes;  "%-10p"

    nes.spaces = 0;
    nes.mince = 0;
    nes.count = 0;
    while(*string == '-' && *(string + 1))
    {
        nes.mince = 1;
        string++;
    }
    nes.num = (unsigned long)res;
    if(ft_isdigit(*string))
    {
        nes.spaces = ft_atoi(string);
        if (nes.spaces > nes.len + 2)
        nes.spaces = nes.spaces - nes.len;
        else 
        nes.spaces = 0;
    }
    else
       nes.spaces = 0;
    while(ft_isdigit(*string))
        string++;
    if (nes.mince == 0)
    {
        while (((nes.spaces)-- > 0))
            nes.count += write(1," ",1);
        write(1,"0x",2);
        nes.count += ft_putptr_fd(res,1,);
        return (nes.count);
    }
    else
    {
        write(1,"0x",2);
        nes.count += ft_putptr_fd(res,1,);
        while (((nes.spaces)-- > 0))
            nes.count += write(1," ",1);
        return (nes.count);
    }
}
