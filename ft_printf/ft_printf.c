/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:09:06 by baouragh          #+#    #+#             */
/*   Updated: 2023/12/12 23:42:35 by baouragh         ###   ########.fr       */
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
   int y = printf("or|%-23.15i||%-11.12u| |%-010.5d| |%-10c| |%%%%%%|\n",765,-1,928727,'C');
    int i = ft_printf("me|%-23.15i||%-11.12u| |%-010.5d| |%-10c| |%%%%%%|\n",765,-1,928727,'C');
    printf("\n%d\n%d\n",y,i);
}