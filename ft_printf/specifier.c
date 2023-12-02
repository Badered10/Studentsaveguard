/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:59:20 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/30 18:14:34 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int specifier(char c,va_list args)
{
    int count;
    count = 0;
        if (c == 'c')
            count += ft_putchar(va_arg(args,int));
        // else if (c == 's')
        //     count += ft_putstr(va_arg(args,char*));
        // else if (c == 'd' || c == 'i')
        //     count += ft_putnbr(va_arg(args,int));
        // else if (c == 'u')
        //     count += ft_putunbr(va_arg(args,unsigned int));
        // else if (c == 'p')
        //     count += ft_putaddres(va_arg(args,));
        // else if (c == 'x')
        //     count += ft_putlwheaxa(va_arg(args,));
        // else if (c == 'X')
        //     count += ft_putuphexa(va_arg(args,));
     else
        count += write(1,&c,1);
    return (count);
}