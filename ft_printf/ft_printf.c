/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:09:06 by baouragh          #+#    #+#             */
/*   Updated: 2023/12/12 16:19:42 by baouragh         ###   ########.fr       */
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
                    t.count += ft_dflags(save_m + 1,va_arg(args,int));
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
    int i = ft_printf("hello %d %-010.4ds sda\n",2123,432);
    printf("hello %d %-010.4ds sda\n",2123,432);
    printf("\n%d\n",i);
}