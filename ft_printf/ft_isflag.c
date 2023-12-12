/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isflag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 09:56:20 by baouragh          #+#    #+#             */
/*   Updated: 2023/12/12 18:34:00 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int ft_isflag(char ch , char *save_m ,va_list args)
{
    f c;
    
    c.count = 0;
    // if (*pose == 'c' || *pose == '%')
    //     c.count = ft_cflags(string,args);
    // else if (*pose == 's')
    //     c.count = ft_sflags(string,args);
    // else if (*pose == 'p')
    //     c.count = ft_pflags(string,args);
    if (ch == 'd' || ch == 'i')
        c.count = ft_dflags(save_m + 1,va_arg(args,int));
    // else if (*pose == 'u')
    //     c.count = ft_uflags(string,args);
    // else if (*pose == 'x' || *pose == 'X')
    //     c.count = ft_xflags(string,args);
    return (c.count);
}