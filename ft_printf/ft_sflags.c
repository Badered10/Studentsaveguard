/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sflags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 08:27:32 by baouragh          #+#    #+#             */
/*   Updated: 2023/12/13 09:41:18 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int ft_sflags(char *string, char *res)
{
    // printf("taqtaq\n");
    f nes;

    nes.display = 0; 
    nes.point = 0;
    nes.mince = 0;
    nes.count = 0;
    // printf("string is'%s'\n",string);
    // printf("res is'%s'\n",res);
    while(*string == '-' && *(string + 1))
    {
        // printf("hahaha");
        nes.mince = 1;
        string++;
    }
    nes.len = (int)ft_strlen(res);
    // printf("lenth %d\n",nes.len);
    if(ft_isdigit(*string))
        nes.spaces = ft_atoi(string);
    else
       nes.spaces = 0; 
    //    printf("spaces after %d\n",nes.spaces);
    while(ft_isdigit(*string))
        string++;
    // printf("\tzero : %d, point %d, mince %d \n",nes.zero , nes.point , nes.mince);
    if (*string == '.' && *(string + 1))
    {
        nes.point = 1;
        string++;
        if(ft_isdigit(*string))
        {                      
            nes.display = ft_atoi(string);
            if (nes.display > nes.len)
            nes.display = nes.len;
            if (nes.spaces > nes.display)
                nes.spaces -= nes.display;
            else
                nes.spaces = 0;
        }
        // nes.width = nes.display + nes.spaces; to remove
    }
    else if (nes.point != 1)
    {
        nes.display = nes.len;
        nes.spaces -= nes.display; 
    }///   printf("'%10.10s'\n",s);
        if (nes.display == nes.spaces)
            nes.spaces = 0;

    // printf("\t dis : %d, sp%d\n",nes.display , nes.spaces);
    if (nes.mince == 1) // printf("'%10.9s'\n",s);
    {
        // printf("1\n"); 
        nes.count += ft_putnstr_fd(res,1,nes.display);
        while ((nes.spaces)-- > 0 )
            nes.count += write(1," ",1);
        return (nes.count);
    }
    else
    {
        // printf("2\n");
        while ((nes.spaces)-- > 0)
            nes.count += write(1," ",1);
         nes.count += ft_putnstr_fd(res,1,nes.display);
        return (nes.count);
    }
}
