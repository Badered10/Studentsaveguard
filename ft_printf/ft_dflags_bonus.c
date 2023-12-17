/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dflags_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 18:00:25 by baouragh          #+#    #+#             */
/*   Updated: 2023/12/17 14:59:05 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void ze_print(f *nes)
{
    if ( nes->zero == 1 )
    {     
        if (nes->d < 0)
            write(1,"-",1);
        while ((nes->zeros)-- > 0)
            nes->count += write(1,"0",1);
        nes->count += ft_putnbr_fd(nes->d,1);
    }
    else
    {
        while ((nes->spaces)-- > 0)
            nes->count += write(1," ",1);
            if (nes->plus == 1 && nes->d >= 0)
            nes->count += write(1,"+",1);
        if (nes->d < 0)
            write(1,"-",1);
        nes->count += ft_putnbr_fd(nes->d,1);
    }
}

static void mp_print(f *nes)
{
    if (nes->mince == 1)
    {
     if(nes->d < 0)
            write(1,"-",1);
        while((nes->zeros)-- > 0)
            nes->count += write(1,"0",1); 
        nes->count += ft_putnbr_fd(nes->d,1);
        while ((nes->spaces)-- > 0)
            nes->count += write(1," ",1);
    }
    else if (nes->point == 1)
    {
        while ((nes->spaces)-- > 0)
            nes->count += write(1," ",1);
        if (nes->plus == 1 && nes->d >= 0)
            nes->count += write(1,"+",1);
        if (nes->d < 0)
            write(1,"-",1);
        while ((nes->zeros)-- > 0)
            nes->count += write(1,"0",1);
        if (nes->tmp != -999999999)
            nes->count += ft_putnbr_fd(nes->d,1);
    }
}

static void ft_checkplus_space(f *nes)
{
    if (nes->space == 1 && nes->d >= 0)
        {
            nes->count = write(1," ",1);
            if ((nes->zero == 1 && nes->tmp <= nes->len) || nes->tmp == -999999999)
                nes->zeros--;
                if (nes->tmp != -999999999 ||nes->point == 0)
                    nes->spaces--;
        }
        else if (nes->plus == 1 && nes->d >= 0)
        {
            if (nes->mince == 1 || (nes->zero && !nes->point))
                nes->count = write(1,"+",1);
           if ((nes->zero == 1 && nes->tmp <= nes->len) || nes->tmp == -999999999)
                nes->zeros--;
            if (nes->tmp != -999999999 || nes->point == 0)
                nes->spaces--;
        }
}

static void ft_checkpoint(char **string, f *nes)
{
      if (*(*string) == '.' )
    {
        nes->point = 1;
        if (*(*string))
            string++;
        if(ft_isdigit(*(*string)))
        {                      
            nes->zeros = ft_atoi(*string);
            nes->tmp = nes->zeros;
            if (nes->zeros > nes->len)
                nes->zeros -= nes->len;
                 else
                     nes->zeros = 0;
        }
    }
        else if (nes->zero == 1)
            nes->zeros = nes->spaces;
        if (((nes->zeros  > 0) || (nes->len == nes->tmp)) && (nes->d < 0 && nes->point == 1)) 
		    nes->zeros ++;
        nes->spaces -= nes->zeros;
}

static void ft_checkspaces(char **string, f *nes)
{
     if(ft_isdigit(*(*string)))
    {
        nes->spaces = ft_atoi(*string);
        if (nes->spaces > nes->len) 
                nes->spaces -= nes->len;
            else 
                nes->spaces = 0;
    }
        else
            nes->spaces = 0;
            while(ft_isdigit(*(*string)))
            (*string)++;
}
static void ft_initialize(f *nes , int x, char *string)
{
    char *str;

    nes->d = x;
    nes->plus = 0;
    nes->space = 0;
    nes->mince = 0;
    nes->zero = 0;
    nes->point = 0;
    nes->zeros = 0;
    nes->count = 0;
    nes->tmp = -999999999;
    
    str = ft_itoa(nes->d);
    nes->len = ft_strlen(str);
    free(str);
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

    ft_initialize(&nes,x,string);
    ft_search(&nes,&string,'d','i');
    ft_checkspaces(&string, &nes);
    ft_checkpoint(&string, &nes);
    ft_checkplus_space(&nes);
    if (nes.mince == 1 || nes.point == 1)
        return(mp_print(&nes),nes.count);
    else
        return(ze_print(&nes),nes.count);
    
}


    // else if (nes.zero == 1 )
    // {     
    //     if (nes.d < 0)
    //         write(1,"-",1);
    //     while ((nes.zeros)-- > 0)
    //         nes.count += write(1,"0",1);
    //     nes.count += ft_putnbr_fd(nes.d,1);
    //     return (nes.count);
    // }
    // else
    // {
    //     while ((nes.spaces)-- > 0)
    //         nes.count += write(1," ",1);
    //         if (nes.plus == 1 && nes.d >= 0)
    //         nes.count += write(1,"+",1);
    //     if (nes.d < 0)
    //         write(1,"-",1);
    //     nes.count += ft_putnbr_fd(nes.d,1);
    //     return (nes.count);
    // }