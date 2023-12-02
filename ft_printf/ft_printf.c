/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:09:06 by baouragh          #+#    #+#             */
/*   Updated: 2023/12/02 18:57:06 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "printf.h"
# include "libft.h"
int ft_printf(char *string , ...)
{
    size_t len;
    int print;
    int count;
    va_list args;

    count = 0;
    va_start(args,string);
    print = 0;
    len = ft_strlen(string);




    
    while (*string)
    {
        if(*string == '%')
        {
            if (!*(++string))
                return 0;
                if (*string == '-')
                    mince_flag(string,args);
                // count += specifier(*string,args);
            // else if (*string == '0')
            // else if (*string == '.')
        }
        else
            count += write(1,string,1);
        string++;
    }
    va_end(args);
    return (count);
}
int main()
{
    int i = ft_printf("asa%c",'k');
    printf("%d\n",i);
}