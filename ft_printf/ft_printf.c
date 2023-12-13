/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:09:06 by baouragh          #+#    #+#             */
/*   Updated: 2023/12/13 11:58:43 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "printf.h"
int ft_printf(char *string , ...)
{
    va_list args;
    f t;
    char *ptr;
    char *specifiers;
    char *save_m;
    ptr = string;
    specifiers = "cspdiuxX%";
    t.count = 0;
    va_start(args,string);
    while (*ptr)
    {
        if(*ptr == '%')
        {
            save_m = ptr;
            ptr++;
            while (*ptr)
            {
                if(ft_strchr(specifiers,*ptr))
                {
                    t.count += ft_isflag(*(ft_strchr(specifiers,*ptr)),save_m ,args);
                    break;
                }
                ptr++;
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
    char * x = NULL;
    char *str;
    str = "|%6.2s| |%6.2d| |%6.2s| |%6.2u| |%6c| |%7.6s|\n ";
    int y = printf(str,"hello", 123, "okey", -231, 'k',x);
    int i = ft_printf(str,"hello", 123, "okey", -231, 'k',x);
    printf("\n%d\n%d\n",y,i);
}