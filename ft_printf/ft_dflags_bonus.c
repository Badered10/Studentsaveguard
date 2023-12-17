/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dflags_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 18:00:25 by baouragh          #+#    #+#             */
/*   Updated: 2023/12/17 12:13:53 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void ft_initialize(f *nes)
{
    nes->plus = 0;
    nes->space = 0;
    nes->mince = 0;
    nes->zero = 0;
    nes->point = 0;
    nes->zeros = 0;
    nes->count = 0;
    nes->tmp = -999999999;
}

void ft_search(f *nes,char **string, char c, char d)
{
     while(ft_isdigit_nz(*(*string)) != 1 && *(*string) != '.' && *(*string) != c && *(*string) != d && *(*(string)))
    {
        if (*(*string) == '+')
        {
            nes->plus = 1;
            nes->space = 0;
        }
        else if (*(*string) == ' ')
            {
                if (nes->plus == 0)
                    nes->space = 1;
            }
        else if(*(*string) == '0')
            {
                if(nes->mince == 0)
                nes->zero = 1;
            }
        else if(*(*string) == '-')
        {
            nes->zero = 0;
            nes->mince = 1;
        }
        (*string)++;
    }
}

int ft_dflags(char *string, int x)
{
    f nes;
    char *str;

    ft_initialize(&nes);
    ft_search(&nes,&string,'d','i');
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
            if ((nes.zero == 1 && nes.tmp <= nes.len) || nes.tmp == -999999999)
                nes.zeros--;
                if (nes.tmp != -999999999 ||nes.point == 0)
                    nes.spaces--;
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
