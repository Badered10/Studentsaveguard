/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pflags_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:40:40 by baouragh          #+#    #+#             */
/*   Updated: 2023/12/17 11:05:25 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
static unsigned long    hexalenth(unsigned long n)
{
	int	res;
		res = 0;
	while (n != 0)
	{
		n /= 16;
		res++;
	}
    return (res);
}

int ft_pflags(char *string, void* res, char c)  
{
    f nes;

    nes.mince = 0;
    nes.count = 0;
    nes.len = 2;
    while(*string == '-' && *(string + 1))
    {
        nes.mince = 1;
        string++;
    }
    nes.num = (unsigned long)res;
     if (nes.num == 0)
        nes.len = 3;
        else
            nes.len += hexalenth(nes.num);
    if(ft_isdigit(*string))
    {
        nes.spaces = ft_atoi(string);
        if (nes.spaces > nes.len)
        nes.spaces = nes.spaces - nes.len ;
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
        nes.count += ft_putptr_fd(nes.num,1,c);
        return (nes.count);
    }
    else
    {
        nes.count += ft_putptr_fd(nes.num,1,c);
        while (((nes.spaces)-- > 0))
            nes.count += write(1," ",1);
        return (nes.count);
    }
}
