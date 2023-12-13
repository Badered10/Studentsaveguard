/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:09:06 by baouragh          #+#    #+#             */
/*   Updated: 2023/12/13 21:45:34 by baouragh         ###   ########.fr       */
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
    char *flags;
    
    ptr = string;
    specifiers = "cspdiuxX%";
    flags = ".0- +#";
    t.count = 0;
    va_start(args,string);
    while (*ptr)
    {
        if(*ptr == '%')
        {
            save_m = ptr;
            ptr++;
            while (*ptr )
            {
                if(ft_strchr(specifiers,*ptr))
                {
                    t.count += ft_isflag(*(ft_strchr(specifiers,*ptr)),save_m ,args);
                    break;
                }
                if(ft_strchr(flags,*ptr) == NULL && ft_isdigit(*ptr) == 0)
                {
                    t.count += write(1,ptr,1);
                    break;
                }
                ptr++;
            }
        }
        else
            t.count += write(1,ptr,1);
        ptr++;
    }
    printf("tcount is %d\n",t.count);
    va_end(args);
    return (t.count);
}

// int main()
// {
//     int y = printf("","hello", 123, "okey", -231, 'k',x);
//     int i = ft_printf("%-010.2s %-010.3d","hello", 123, "okey", -231, 'k',x);
//     printf("\n%d\n%d\n",y,i);
// }