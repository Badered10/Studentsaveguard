/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xsflags_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:18:51 by baouragh          #+#    #+#             */
/*   Updated: 2023/12/17 10:54:21 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
static int	hexalenth(unsigned long n)
{
	int res;
    
    res = 1;
	if (n > 0)
		res = 0;
	while (n != 0)
	{
		n /= 16;
		res++;
	}
    return (res);
}
int ft_xsflags(char *string, unsigned int x , char c)
{
    f nes;

    nes.mince = 0;
    nes.zero = 0;
    nes.hashtag = 0;
    nes.point = 0;
    nes.zeros = 0;
    nes.count = 0;
    nes.len = 0;
    nes.tmp = -999999999;
    
    while(ft_isdigit_nz(*string) != 1 && *string != '.' && *string != 'x' && *string != 'X') 
    {
         while (*string == '#' && *(string + 1))
        {
            nes.hashtag = 1;
            string++;
        }
         if(nes.mince == 0)
        {
            
            while(*string == '0' && *(string + 1))
            {
                nes.zero = 1;
                string++;
            }
        }
         else if (nes.mince == 1 && *string == '0')
        {
            while(*string == '0' && *(string + 1))
                string++;
        }
        while(*string == '-' && *(string + 1))
        {
            nes.zero = 0;
            nes.mince = 1;
            string++;
        }
    }
    nes.len += hexalenth(x);
    
    if(ft_isdigit(*string))
    {
        nes.spaces = ft_atoi(string);
        if (nes.spaces > nes.len)          
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
        nes.spaces -= nes.zeros;
    if (nes.hashtag == 1 && x)
        {
            if (((nes.mince == 1 && x ) || (nes.zero && !nes.point )) && c == 'x')
                nes.count += write(1,"0x",2);
                else if (((nes.mince == 1 && x ) || (nes.zero && !nes.point )) && c !='x')
                    nes.count += write(1,"0X",2);
           if ((nes.zero == 1 && nes.tmp <= nes.len) || nes.tmp == -999999999)
                nes.zeros-=2;
            if (nes.tmp != -999999999 || nes.point == 0)
                nes.spaces-=2;
        }
    if (nes.mince == 1)
    {
        while ((nes.zeros)-- > 0)
            nes.count += write(1,"0",1);
        nes.count += ft_puthexa_fd(x,1 ,c);
        while ((nes.spaces)-- > 0 )
            nes.count += write(1," ",1);
        return (nes.count);
    }
    else if (nes.point == 1)
    {
        while ((nes.spaces)-- > 0)
            nes.count += write(1," ",1);
        if (nes.hashtag == 1 && x && c == 'x')
            nes.count += write(1,"0x",2);
            else if (nes.hashtag == 1 && x && c != 'x')
                nes.count += write(1,"0X",2);
        while ((nes.zeros)-- > 0)
            nes.count += write(1,"0",1);
        nes.count += ft_puthexa_fd(x,1 ,c);
        return (nes.count);
    }
    else if (nes.zero == 1 )
    {
        while ((nes.zeros)-- > 0)
            nes.count += write(1,"0",1);
        nes.count += ft_puthexa_fd(x,1 ,c);
        return (nes.count);
    }
    else
    {
        while ((nes.spaces)-- > 0)
            nes.count += write(1," ",1);
        if (nes.hashtag == 1 && x && c == 'x')
            nes.count += write(1,"0x",2);
            else if (nes.hashtag == 1 && x && c != 'x')
                nes.count += write(1,"0X",2);
        nes.count += ft_puthexa_fd(x,1 ,c);
        return (nes.count);
    }
}
