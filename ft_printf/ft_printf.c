/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:09:06 by baouragh          #+#    #+#             */
/*   Updated: 2023/12/12 12:33:21 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "printf.h"
int ft_printf(char *string , ...)
{
    va_list args;
    f t;
    char *ptr;
    char *specifiers;

    ptr = string;
    specifiers = "cspdiuxX%";
    t.count = 0;
    va_start(args,string);
    while (*ptr)
    {
        if(*ptr == '%')
        {
            if (!*(++ptr))
                return 0;
            while (*ptr)
            {
                if(ft_strchr(string,*ptr))
                {
                    t.count += ft_isflag(ft_strchr(string,*ptr),string,args);
                    break;
                }
                ptr ++;
            }
        }
        else
            t.count += write(1,ptr,1);
        ptr++;
    }
    va_end(args);
    return (t.count);
}
int main()
{
    int i = ft_printf("hello %d sda",23);
    printf("\n%d\n",i);
}