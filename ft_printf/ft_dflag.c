/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dflag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 18:00:25 by baouragh          #+#    #+#             */
/*   Updated: 2023/12/11 21:27:00 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h" 

int d_flags(char *string, va_list args)
{   
    while(*string == '-' && *(string + 1))
    {
        f.mince = 1;
        string++;
    }
    while(*string == '0' && *(string + 1))
    {
        if (f.mince != 1)
        f.zero = 1;
        string++;
    }
    f.d = va_arg(args,int);
    f.len = ft_strlen(ft_itoa(f.d));
    if(ft_isdigit(*string))
    {
        f.spaces = ft_atoi(string);
        if (f.spaces > f.len)
        f.spaces = f.spaces - f.len;
        else 
        f.spaces = 0;
    }
    else
       f.spaces = 0; 
    while(ft_isdigit(*string))
        string++;
    if (*string == '.' && *(string + 1))
    {
        f.point = 1;
        string++;
        if(ft_isdigit(*string))
        {                      
            f.zeros = ft_atoi(string);   
            if (f.zeros > f.len)
            f.zeros = f.zeros - f.len;
            else
            f.zeros = 0;
            f.spaces = f.spaces - f.zeros;
        }
        else
            f.zeros = 0;
        if (f.zeros = f.spaces)
            f.spaces = 0;
        f.width = f.zeros + f.spaces;
    }
    if (f.mince == 1)
    {
        while ((f.zeros)-- > 0)
            f.count += write(1,"0",1);
        f.count += ft_putnbr_fd(f.d,1);
        while ((f.spaces)-- > 0 )
            f.count += write(1," ",1);
        return (f.count);
    }
    else
    {
        while ((f.spaces)--)
            f.count += write(1," ",1);
        while ((f.zeros)--)
            f.count += write(1,"0",1);
        f.count += ft_putnbr_fd(f.d,1);
        return (f.count);
    }
}