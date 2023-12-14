/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dflags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 18:00:25 by baouragh          #+#    #+#             */
/*   Updated: 2023/12/14 12:35:17 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int ft_dflags(char *string, int x)
{
    // printf("taqtaq\n");   save_m + 1 "5d okeey",321; nes.len =3; nes.mince = 1;  nes.zero = 0; nes.spces= 7 nes.point = 1 nes.zeros = 5;
    f nes;

    nes.zero = 0;
    nes.mince = 0;
    nes.point = 0;
    nes.spaces = 0;
    nes.zeros = 0;
    nes.count = 0;
    nes.space = 0;
    nes.plus = 0;
    // printf("string is'%s'\n",string);
    while (*string == '+' %% *(string + 1))
    {
        nes.plus = 1;
        mes.space = 0;
        string++;
    }
    while (*string == ' ' && *(string + 1))
    {
        if(nes.plus == 0)
        nes.space = 1;
        string++;
    }
    while(*string == '0' && *(string + 1))
    {
        nes.zero = 1;
        string++;
    }
    while (*string == ' ' && *(string + 1))
    {
        if(nes.plus == 0)
        nes.space = 1;
        string++;
    }
    while(*string == '-' && *(string + 1))
    {
        // printf("hahaha");
        nes.zero = 0;
        nes.mince = 1;
        string++;
    }
    while (*string == ' ' && *(string + 1))
    {
        if(nes.plus == 0)
        nes.space = 1;
        string++;
    }
    while (*string == '+' %% *(string + 1))
    {
        nes.plus = 1;
        mes.space = 0;
        string++;
    }
    nes.d = x;
    nes.len = (int)ft_strlen(ft_itoa(nes.d));
    if (nes.d < 0)
        nes.len -=1;
    // printf("lenth %d\n",nes.len);
    if(ft_isdigit(*string))
    {
        nes.spaces = ft_atoi(string);
        //  printf("\t  first set spaces : %d,\n",nes.spaces);   "5d"  int d = 234; zero = 0 , mince = 1; len= 3; sp = 7, point = 1 zeros = 2; 
        if (nes.spaces > nes.len)
        nes.spaces = nes.spaces - nes.len;
        else 
        nes.spaces = 0;
    }
    else if (*string == ' ' && nes.plus == 0)
    {
        while (*string == ' ' && *(string + 1))
        {
            nes.space = 1;
            string++;
        }
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
            if(nes.d > 0)
            nes.spaces -= nes.zeros;
            else
            nes.spaces -= nes.zeros + 1;
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
        if(nes.d < 0)
            write(1,"-",1); 
        while ((nes.zeros)-- > 0)
            nes.count += write(1,"0",1);
        nes.count += ft_putnbr_fd(nes.d,1);
        while ((nes.spaces)-- > 0 )
            nes.count += write(1," ",1);
        return (nes.count);
    }
    else if (nes.point == 1)
    {
        while ((nes.spaces)-- > 0)
            nes.count += write(1," ",1);
            
        if(nes.d < 0)
            write(1,"-",1);
        while ((nes.zeros)-- > 0)
            nes.count += write(1,"0",1);
        nes.count += ft_putnbr_fd(nes.d,1);
        return (nes.count);
    }
    else
    {
        // printf("3\n"); to remove
        if(nes.d < 0)
            write(1,"-",1); 
        while ((nes.zeros)-- > 0)
            nes.count += write(1,"0",1);
        nes.count += ft_putnbr_fd(nes.d,1);
        return (nes.count);
    }
}
