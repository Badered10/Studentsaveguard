/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:09:06 by baouragh          #+#    #+#             */
/*   Updated: 2023/12/12 23:04:47 by baouragh         ###   ########.fr       */
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
                    t.count += ft_isflag(*(ft_strchr(specifiers,*ptr)),save_m , args);
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
   int y = printf("or|%-11.12u| |%-010.5d| |%-010c| |%%%%%%|\n",0,12,'l');
    int i = ft_printf("me|%-11.12u| |%-010.5d| |%-010c| |%%%%%%|\n",0,12,'l');
    printf("\n%d\n%d\n",y,i);
}