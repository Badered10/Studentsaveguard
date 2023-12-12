/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uflags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 22:13:54 by baouragh          #+#    #+#             */
/*   Updated: 2023/12/12 22:58:00 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int ft_uflags(char *string, unsigned int x)
{
    // printf("taqtaq\n");
    f nes;

    nes.zeros = 0;
    nes.zero = 0;
    nes.spaces = 0;
    nes.point = 0;
    nes.mince = 0;
    nes.count = 0;
    // printf("string is'%s'\n",string);
    while(*string == '0' && *(string + 1))
    {
        nes.zero = 1;
        string++;
    }
    while(*string == '-' && *(string + 1))
    {
        // printf("hahaha");
        nes.zero = 0;
        nes.mince = 1;
        string++;
    }
    nes.len = ft_strlen(ft_itoa(x));
    if(ft_isdigit(*string))
    {
        nes.spaces = ft_atoi(string);
        //  printf("\t  first set spaces : %d,\n",nes.spaces);
        if (nes.spaces > nes.len)
        nes.spaces = nes.spaces - nes.len;
        else 
        nes.spaces = 0;
    }
    else
       nes.spaces = 0; 
    while(ft_isdigit(*string))
        string++;
    // printf("\tzero : %d, point %d, mince %d \n",nes.zero , nes.point , nes.mince);
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
        // nes.width = nes.zeros + nes.spaces; to remove
    }
    else if (nes.zero == 1 && nes.point != 1 && nes.mince != 1)
    {
        // printf("done dude!\n");
            nes.zeros = nes.spaces;
    }
        if (nes.zeros == nes.spaces)
            nes.spaces = 0;

    // printf("\tzeros : %d, sp%d\n",nes.zeros , nes.spaces);
    if (nes.mince == 1)
    {
        // printf("1\n");  to remove  
        while ((nes.zeros)-- > 0)
            nes.count += write(1,"0",1);
        nes.count += ft_putunbr_fd(x,1);
        while ((nes.spaces)-- > 0 )
            nes.count += write(1," ",1);
        return (nes.count);
    }
    else if (nes.point == 1)
    {
        // printf("2\n"); to remove
        while ((nes.spaces)-- > 0)
            nes.count += write(1," ",1);
        while ((nes.zeros)--)
            nes.count += write(1,"0",1);
        nes.count += ft_putunbr_fd(x,1);
        return (nes.count);
    }
    else
    {
        // printf("3\n"); to remove
        while ((nes.zeros)-- > 0)
            nes.count += write(1,"0",1);
        nes.count += ft_putunbr_fd(x,1);
        return (nes.count);
    }
}
