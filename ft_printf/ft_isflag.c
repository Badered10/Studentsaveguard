/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isflag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 09:56:20 by baouragh          #+#    #+#             */
/*   Updated: 2023/12/12 11:23:04 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int ft_isflag(char *pose ,char *string ,va_list args)
{
    f c;

    if (*pose == 'c' || *pose == '%')
        c.count = ft_cflags(string,args);
    else if (*pose == 's')
        c.count = ft_sflags(string,args);
    else if (*pose == 'p')
        c.count = ft_pflags(string,args);
    else if (*pose == 'd' || *pose == 'i')
        c.count = ft_dflags(string,args);
    else if (*pose == 'u')
        c.count = ft_uflags(string,args);
    else if (*pose == 'x' || *pose == 'X')
        c.count = ft_xflags(string,args);
}