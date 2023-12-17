/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dflags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 18:00:25 by baouragh          #+#    #+#             */
/*   Updated: 2023/12/17 09:26:28 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int ft_dflags(char *string, int x)
{
    // printf("taqtaq\n");   save_m + 1 "5d okeey",321; nes.len =3; nes.mince = 1;  nes.zero = 0; nes.spces= 7 nes.point = 1 nes.zeros = 5;
    f nes;
    char *str;

    nes.plus = 0;
    nes.space = 0;
    nes.mince = 0;
    nes.zero = 0;
    nes.point = 0;
    nes.zeros = 0;
    nes.count = 0;
    nes.tmp = -999999999;
       while(ft_isdigit_nz(*string) != 1 && *string != '.' && *string != 'd' && *string != 'i')
    {
        while (*string == '+' && *(string + 1))
        {
            nes.plus = 1;
            nes.space = 0;
            string++;
        }
        while (*string == ' ' && *(string + 1))
            {
                if (nes.plus == 0)
                    nes.space = 1;
                string++;
            }
        while(*string == '0' && *(string + 1))
            {
                if(nes.mince == 0)
                nes.zero = 1;
                string++;
            }
        while(*string == '-' && *(string + 1))
        {
            nes.zero = 0;
            nes.mince = 1;
            string++;
        }
    }
    nes.d = x;
    str = ft_itoa(nes.d);
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
        if (((nes.zeros  > 0) || (nes.len == nes.tmp)) && (nes.d < 0 && nes.point == 1)) 
		    nes.zeros ++;
        nes.spaces -= nes.zeros;

        
        if (nes.space == 1 && nes.d >= 0)
        {
            nes.count = write(1," ",1);
            // printf(" zr %d \n",nes.zeros);
            if ((nes.zero == 1 && nes.tmp <= nes.len) || nes.tmp == -999999999)
                nes.zeros--;
                if (nes.tmp != -999999999 ||nes.point == 0)
                    nes.spaces--;
                    // printf(" zr %d \n",nes.zeros);
                    // nes.zeros++;
        }
        else if (nes.plus == 1 && nes.d >= 0)
        {
            if (nes.mince == 1 || (nes.zero && !nes.point))
                nes.count = write(1,"+",1);
           if ((nes.zero == 1 && nes.tmp <= nes.len) || nes.tmp == -999999999)
                nes.zeros--;
            if (nes.tmp != -999999999 || nes.point == 0)
                nes.spaces--;
        }
        
            
    if (nes.mince == 1)
    {
        if(nes.d < 0)
            write(1,"-",1);
        while((nes.zeros)-- > 0)
            nes.count += write(1,"0",1); 
        nes.count += ft_putnbr_fd(nes.d,1);
        while ((nes.spaces)-- > 0)
            nes.count += write(1," ",1);
        return (nes.count);
    }
    else if (nes.point == 1)  
    {
        while ((nes.spaces)-- > 0)
            nes.count += write(1," ",1);
        if (nes.plus == 1 && nes.d >= 0)
            nes.count += write(1,"+",1);
        if (nes.d < 0)
                write(1,"-",1);
            while ((nes.zeros)-- > 0)
                nes.count += write(1,"0",1);
                // printf("tmp %d,",nes.tmp);
                if (nes.tmp != -999999999)
                    nes.count += ft_putnbr_fd(nes.d,1);
        return (nes.count);
    }
    else if (nes.zero == 1)
    {     
        // printf(" zr %d \n",nes.zeros);
        if (nes.d < 0)
            write(1,"-",1);
        while ((nes.zeros)-- > 0)
            nes.count += write(1,"0",1);
        nes.count += ft_putnbr_fd(nes.d,1);
        return (nes.count);
    }
    else
    {
        while ((nes.spaces)-- > 0)
            nes.count += write(1," ",1);
            if (nes.plus == 1 && nes.d >= 0)
            nes.count += write(1,"+",1);
        if (nes.d < 0)
            write(1,"-",1);
        nes.count += ft_putnbr_fd(nes.d,1);
        return (nes.count);
    }
}