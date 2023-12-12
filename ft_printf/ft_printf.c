/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:09:06 by baouragh          #+#    #+#             */
/*   Updated: 2023/12/12 10:07:55 by baouragh         ###   ########.fr       */
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
                ft_strchr(string,)
                ptr++;
            }
                // if (*string == '-')
                //     mince_flag(string,args);
                // count += specifier(*string,args);
            // else if (*string == '0')
            // else if (*string == '.')
        }
        else
            count += write(1,ptr,1);
        ptr++;
    }
    va_end(args);
    return (count);
}
int main()
{
    int i = ft_printf("asa%c",'k');
    printf("%d\n",i);
}