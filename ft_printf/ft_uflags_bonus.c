/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uflags_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 22:13:54 by baouragh          #+#    #+#             */
/*   Updated: 2023/12/17 09:14:00 by baouragh         ###   ########.fr       */
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
    nes.tmp = -999999999;
    char *str;
    // printf("string is'%s'\n",string);
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
    str = ft_uitoa(x);
    nes.len = ft_strlen(str);
    free(str);
    if(ft_isdigit(*string))
    {
        nes.spaces = ft_atoi(string);
        if (nes.spaces > nes.len)          //sp  = 47 
                nes.spaces -= nes.len;
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
            nes.tmp = nes.zeros;
            if (nes.zeros > nes.len)
                nes.zeros -= nes.len;
                 else
                     nes.zeros = 0;
        }
    }
        else if (nes.zero == 1)
            nes.zeros = nes.spaces;
        // if (((nes.zeros  > 0) || (nes.len == nes.tmp)) && (nes.point == 1)) 
		//     nes.zeros ++;
            
        nes.spaces -= nes.zeros;
        
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
        while ((nes.zeros)-- > 0)
            nes.count += write(1,"0",1);
        nes.count += ft_putunbr_fd(x,1);
        return (nes.count);
    }
    else if (nes.zero == 1)
    {     
        // printf(" zr %d \n",nes.zeros);
        while ((nes.zeros)-- > 0)
            nes.count += write(1,"0",1);
        nes.count += ft_putunbr_fd(x,1);
        return (nes.count);
    }
    else
    {
        // printf("3\n"); to remove
        while ((nes.spaces)-- > 0)
            nes.count += write(1," ",1);
        nes.count += ft_putunbr_fd(x,1);
        return (nes.count);
    }
}
