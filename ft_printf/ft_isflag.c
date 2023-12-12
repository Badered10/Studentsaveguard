/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isflag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 09:56:20 by baouragh          #+#    #+#             */
/*   Updated: 2023/12/12 21:06:31 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int ft_isflag(char ch , char *save_m ,va_list args)
{
    f c;
    
    c.count = 0;
    if (ch == 'c' || ch == '%')
        c.count = ft_cflags(save_m + 1,va_arg(args,int));
    // else if (ch == 's')
    //     c.count = ft_sflags(string,args);
    // else if (ch == 'p')
    //     c.count = ft_pflags(string,args);
    else if (ch == 'd' || ch == 'i')
        c.count = ft_dflags(save_m + 1,va_arg(args,int));
    // else if (ch == 'u')
    //     c.count = ft_uflags(string,args);
    // else if (ch == 'x' || ch == 'X')
    //     c.count = ft_xflags(string,args);
    return (c.count);
}